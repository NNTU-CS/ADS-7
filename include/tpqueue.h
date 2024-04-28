// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
 private:
    struct Node {
        Node* next;
        T data;
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

    void push(const T& elem) {
        Node* newNode = new Node{elem, nullptr};

        if (!head || head->data.prior < elem.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= elem.prior) {
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
        T data;
        data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
};

struct SYM {
char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
