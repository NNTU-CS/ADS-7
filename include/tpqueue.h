// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T>
struct QueueNode {
  T data;
  QueueNode* next;
};
template<typename T>
class TPQueue {
private:
QueueNode<T>* head;
public:
TPQueue() : head(nullptr) {}
 ~TPQueue() {
    while (head) {
     QueueNode<T>* temp = head;
     head = head->next;
     delete temp;
     }
   }
void push(const T& elem) {
  QueueNode<T>* newNode = new QueueNode<T>{elem, nullptr};
  if (!head || head->data.prior < elem.prior) {
    newNode->next = head;
    head = newNode;
  } else {
    QueueNode<T>* current = head;
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
  QueueNode<T>* temp = head;
  T item = temp->data;
  head = head->next;
  delete temp;
  delete temp;
}
bool isEmpty() const {
  return head == nullptr;
}
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
