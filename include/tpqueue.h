// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template <typename T>

class TPQueue {
 private:
    struct Node {
        SYM data;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    void push(SYM sym) {
        Node* new_node = new Node{ sym, nullptr };

        if (head == nullptr || sym.prior > head->data.prior) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* t = head;
            while (t->next != nullptr && sym.prior <= t->next->data.prior) {
                t = t->next;
            }
            new_node->next = t->next;
            t->next = new_node;
        }
    }

    SYM pop() {
        if (head == nullptr) {
            std::cout << "Queue is empty" << std::endl;
            return SYM{ '0', 0 };
        }

        SYM sym = head->data;
        Node* t = head;
        head = head->next;
        delete t;

        return sym;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
