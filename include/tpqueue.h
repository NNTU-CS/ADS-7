// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node *next;
  };
  Node *first;
  Node *last;
  int counter;

 public:
  TPQueue() : first(nullptr), last(nullptr), counter(0) {}
  void push(const T &value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (first == nullptr) {
      first = newNode;
      last = newNode;
      counter++;
      return;
    }

    if ((first->data.prior) < value.prior) {
      newNode->next = first;
      first = newNode;
      counter++;
      return;
    }

    Node *end = first;

    for (int i = counter - 1; i > 0; i--) {
      if (end->next != nullptr && end->next->data.prior >= value.prior) {
        end = end->next;
      }
    }

    newNode->next = end->next;
    end->next = newNode;

    if (newNode->next == nullptr) {
      last = newNode;
    }
  }
  T pop() {
    Node *temp = first;
    T result = temp->data;
    first = first->next;
    delete temp;
    return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
