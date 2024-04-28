// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

struct Node {
    SYM data;
    Node* next;
};

class TPQueue {
private:
    Node* head;
public:
    TPQueue() {
        head = nullptr;
    }

    void push(SYM item) {
        Node* newNode = new Node;
        newNode->data = item;
        
        if (!head || head->data.prior < item.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= item.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    SYM pop() {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }
        Node* temp = head;
        SYM item = head->data;
        head = head->next;
        delete temp;
        return item;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << "Character: " << current->data.ch << ", Priority: " << current->data.prior << std::endl;
            current = current->next;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
