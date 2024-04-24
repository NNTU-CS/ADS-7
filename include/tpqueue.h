// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
struct Node {
    T data;
    int prior;
    Node<T>* next;
    Node(const T& d, int p) : data(d), prior(p), next(nullptr) {}
};

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
    Node<T>* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& data) {
    Node<T>* newNode = new Node<T>(data, data.prior);

    if (!head || data.prior > head->prior) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next && data.prior <= current->next->prior) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T result = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return result;
    }

    bool isEmpty() const {
        return !head;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
