// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template <typename T>
struct QueueNode {
    T value;
    int priority;
    QueueNode<T>* next;
    QueueNode(const T& val, int prio) : 
    value(val), 
    priority(prio), 
    next(nullptr) {}
};

struct SYM {
    char ch;
    int prior;
};

template <typename T>
class TPQueue {
 private:
    QueueNode<T>* front;

 public:
    TPQueue() : front(nullptr) {}

    void push(const T& item) {
        QueueNode<T>* newNode = new QueueNode<T>(item, item.prior);
        if (!front || item.prior > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            QueueNode<T>* curr = front;
            while (curr->next && item.prior <= curr->next->priority) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            throw std::string("Queue is empty");
        }
        T result = front->value;
        QueueNode<T>* temp = front;
        front = front->next;
        delete temp;
        return result;
    }

    bool isEmpty() const {
        return !front;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
