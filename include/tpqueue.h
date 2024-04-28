// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
  typedef struct node {
    T value;
    struct node* next;
  } Node;
  Node* front;

 public:
  TPQueue() : front(nullptr) {}
  ~TPQueue() {
    while (front != nullptr)
      pop();
  }
  void push(const T& value) {
    Node* temp, *curr, *pre = nullptr;
    temp = new Node;
    temp->value = value;
    if (front == nullptr || value.prior > front->value.prior) {
      temp->next = front;
      front = temp;
    } else {
      curr = front;
      while (curr && value.prior <= curr->value.prior) {
        pre = curr;
        curr = curr->next;
      }
      temp->next = pre->next;
      pre->next = temp;
    }
  }
  T pop() {
    if (front == nullptr) {
      throw std::string("Empty");
    } else {
      Node* temp;
      temp = front;
      T value = temp->value;
      front = temp->next;
      delete temp;
      return value;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
