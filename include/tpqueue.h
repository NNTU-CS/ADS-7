// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
struct SYM {
    char ch;
    int prior;
};

struct Node {
    SYM data;
    Node* next;
};

template<typename T>
class TPQueue {
 private:
    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    void push(const SYM& item) {
        Node* newNode = new Node{item, nullptr};
        if (!head || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && item.prior <= current->next->data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    SYM pop() {
        if (!head) {
            std::cerr << "Queue is empty\n";
            return SYM{'\0', 0};
        }
        Node* temp = head;
        SYM item = head->data;
        head = head->next;
        delete temp;
        return item;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
