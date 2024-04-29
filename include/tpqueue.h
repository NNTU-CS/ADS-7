// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

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
        Node* temp = new Node{ value, nullptr };
        if (!head || value.prior > head->data.prior) {
            temp->next = head;
            head = temp;
        }
        else {
            Node* current = head;
            while (current->next && value.prior <= current->next->data.prior) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }
    T pop() {
        if (!head) {
            throw std::string("Queue empty");
        }
        T res = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return res;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
