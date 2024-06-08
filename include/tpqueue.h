// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    void push(const T& item) {
        Node<T>* newNode = new Node<T>(item, nullptr);
        if (!head || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next && item.prior <= current->next->data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    T pop() {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }
        T item = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return item;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
