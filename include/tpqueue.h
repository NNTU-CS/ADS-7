// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

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
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node{value, nullptr};
        if (!head || value.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && value.prior <= current->next->data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T pop() {
        if (!head) {
            throw std::out_of_range("Queue empty");
        }
        T result = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return result;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
