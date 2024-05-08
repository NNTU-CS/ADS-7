// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

class Node {
 public:
    T data;
    Node* next;
    Node( T data, Node* next ) : data{data},
                                 next{next} {};
};

template<typename T>
class TPQueue {
 private:
    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        for (;head;) {
            pop();
        }
    }
    void push(const T& value) {
        Node* temp = new Node( value, nullptr );
        if (!head || value.prior > head->data.prior) {
            temp->next = head;
            head = temp;
        } else {
            Node* curr = head;
            for (;curr->next && value.prior <= curr->next->data.prior;) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    T pop() {
        if (!head) {
            throw std::underflow_exception("Queue empty");
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
