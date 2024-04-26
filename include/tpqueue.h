// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
private:
    struct node {
        T data;
        node* next;
    };
    node* head;
    node* tail;

public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue() {
        while (head) {
            node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push(const T& value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            if (newNode->data.prior > head->data.prior) {
                newNode->next = head;
                head = newNode;
            }
            else {
                node* current = head;
                while (current->next && (current->next->data.prior > newNode->data.prior)) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                if (!newNode->next) {
                    tail = newNode;
                }
            }
        }
    }

    T pop() {
        if (head) {
            T value = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            return value;
        }
        return T();
    }
};
