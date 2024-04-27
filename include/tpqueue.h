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
 private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& value) {
        Node* newNode = new Node{value, nullptr};

        if (!head || head->data.prior < value.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= value.prior) {
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

        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
