// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

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

template<typename  T>
class TPQueue {
 private:
    Node<T>* head;

 public:
    TPQueue() : head(nullptr) {}

    void push(const T& data) {
    Node<T>* newNode = new Node<T>(data, data.prior);

    if (!head || data.prior > head->prior) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* present = head;

        while (present->next && data.prior <= present->next->prior) {
            present = present->next;
        }

        newNode->next = present->next;
        present->next = newNode;
    }
}

    T pop() {
        if (isEmpty()) {
          throw std::string("Queue is empty");
        }

        T res = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;

        return  res;
    }

    bool isEmpty() const {
        return !head;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
