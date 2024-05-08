// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class Node {
 public:
    T data;
    Node* next;
    Node( T data, Node<T>* next ) : data{data}, next{next} {};
};

template<typename T>
class TPQueue {
 private:
    Node<T>* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        for (;head;) {
            pop();
        }
    }
    void push(const T& value) {
        Node<T>* temp = new Node<T>( value, nullptr );
        if (!head || value.prior > head->data.prior) {
            temp->next = head;
            head = temp;
        } else {
            Node<T>* curr = head;
            for (;curr->next && value.prior <= curr->next->data.prior;) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    T pop() {
        if (!head) {
            throw std::underflow_error("Queue empty");
        }
        T res = head->data;
        Node<T>* temp = head;
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
