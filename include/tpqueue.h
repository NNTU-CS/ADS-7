// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
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

    Node* head, * tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    void push(const SYM& a) {
        Node* ptr = new Node{ a, nullptr };

        if (!head || head->data.prior < a.prior) {
            ptr->next = head;
            head = ptr;
        } else {
            Node* cur = head;
            while (cur->next && cur->data.prior >= a.prior) {
                cur = cur->next;
            }
            ptr->next = cur->next;
            cur->next = ptr;
        }

        if (!tail) {
            tail = head;
        }
    }

    SYM pop() {
        if (!head) {
            throw "empty!";
        }

        SYM data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (!head) {
            tail = nullptr;
        }

        return data;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
