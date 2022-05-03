// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
  };
  Node* first;

 public:
  TPQueue():first(nullptr) {}
  void push(T value) {
    Node* first = first;
    if (first == nullptr) {
      first = new Node;
      first = first;
      first->data = value;
      first->next = nullptr;
    } else {
        Node* temp = new Node;
        temp->data = value;
        if (first->data.prior < temp->data.prior) {
          temp->next = first;
          first = temp;
          return;
        }
        while (first != nullptr) {
          if ((first->data.prior) >= (temp->data.prior) &&
        ((first->next) == nullptr ||
         (((first->data.prior) < (temp->data.prior))
          || ((first->next) != nullptr &&
              first->next->data.prior < (temp->data.prior))))) {
            temp->next = first->next;
            first->next = temp;
            return;
          }
          first = first->next;
        }
     }
  }
  T pop() {
    Node *first = nullptr;
    first = first;
    if (first != nullptr) {
        T extract = first->data;
        first = first->next;
        return extract;
    } else {
        throw "Empty!";
    }
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
