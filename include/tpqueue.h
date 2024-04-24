// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <stdexcept>
#include <string>

template<typename T>
class TPQueue{
 private:
    struct Node {
        SYM data;
        Node* next;
    };
    Node* prev;
 public:
    TPQueue() : prev(nullptr) {}

    void push(const SYM& data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (prev == nullptr || prev->data.prior < data.prior) {
            newNode->next = prev;
            prev = newNode;
        } else {
            Node* current = prev;
            while (current->next != nullptr && current->next->data.prior >= data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    SYM pop() {
        if (prev == nullptr) {
            throw std::string("Queue is empty");
        }
        Node* t = prev;
        prev = prev->next;
        SYM data = t->data;
        delete t;
        return data;
    }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
