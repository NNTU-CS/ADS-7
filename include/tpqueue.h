// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T>
class TPQueue {
    QueueNode* head;
    QueueNode* tail;
public:
  TPQueue() : head(nullptr), tail(nullptr) {}

void push(const T& item) {
        QueueNode* newNode = new QueueNode;
        newNode->data = item;
        newNode->next = nullptr;

    if (!head) {
      head = tail = newNode;
    } else {
      if (head->data.prior < item.prior) {
        newNode->next = head;
        head = newNode;
      } else {
        QueueNode* current = head;
        while (current->next && current->next->data.prior >= item.prior) {
          current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) {
          tail = newNode;
        }
      }
    }
  }
T pop() {
  if (!head) {
    throw std::out_of_range("Queue is empty");
  }
  T item = head->data;
  QueueNode* temp = head;
  head = head->next;
  delete temp;
  return item;
}
bool isEmpty() const {
  return head == nullptr;
}
void printQueue() const {
  QueueNode* current = head;
  while (current) {
    std::cout << "(" << current->data.ch << ", " << current->data.prior << ") ";
    current = current->next;
  }
  std::cout << std::endl;
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
