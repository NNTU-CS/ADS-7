// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <stdexcept>
#include <string>

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        SYM data;
        Node* next;
    };
    Node* prev;

 public:
    TPQueue() : prev(nullptr) {}

    ~TPQueue() {
      Node* temp;
      while (prev) {
        temp = prev;
        prev = prev->next;
        delete temp;
      }
    }
    void push(const SYM& el) {
        Node* newNode = new Node;
        newNode->data = el;
        if (prev == nullptr || prev->data.prior < el.prior) {
            newNode->next = prev;
            prev = newNode;
        } else {
            Node* current = prev;
            while (current->next != nullptr) {
                if (current->next->data.prior >= el.prior) {
                  current = current->next;
                }
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

#endif  // INCLUDE_TPQUEUE_H_
