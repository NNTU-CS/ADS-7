// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

template <typename T>
class TPQueue {
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* head;
        Node* tail;

    public:
        TPQueue() : head(nullptr), tail(nullptr) {}
        void push(const T& data) {
            Node* newNode = new Node{data, nullptr};
            if (!head || head->data.prior < data.prior) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                while (current->next && current->next->data.prior >= data.prior) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
            if (!tail) {
                tail = head;
            }
        }
        T pop() {
            if (!head) {
                throw std::out_of_range("Queue is empty");
            }
            T data = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) {
                tail = nullptr;
            }
            return data;
        }
        bool isEmpty() const {
            return !head;
        }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
