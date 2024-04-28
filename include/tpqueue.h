// Copyright 2022 NNTU-CS
#include <iostream>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_


struct SYM {
    char ch;
    int prior;
};


struct Node {
    SYM data;
    Node* next;

    explicit Node(const SYM& data) : data(data), next(nullptr) {}
};

class TPQueue {
private:
    Node* head;
    Node* tail;


public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void push(const SYM& data) {
        Node* newItem = new Node(data);
        if (!head || data.prior > head->data.prior) {
            newItem->next = head;
            head = newItem;
        } else {
            Node* current = head;
            while (current->next && data.prior <= current->next->data.prior) {
                current = current->next;
            }
            newItem->next = current->next;
            current->next = newItem;
        }
        if (!tail || data.prior < tail->data.prior) {
            tail = newItem;
        }
    }


    SYM pop() {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }
        SYM data = head->data;
        Node* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
