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
  Node* first_node;

 public:
  TPQueue():first_node(nullptr) {}
  void push(T value) {
    Node* first = first_node;
    if (first == nullptr) {
      first = new Node;
      first_node = first;
      first->data = value;
      first->next = nullptr;
    } else {
        Node* temp = new Node;
        temp->data = value;
        if (first->data.prior < temp->data.prior) {
          temp->next = first;
          first_node = temp;
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
    first = first_node;
    if (first != nullptr) {
        T extract = first->data;
        first_node = first->next;
        return extract;
    } else {
        throw "Empty queue!";
    }
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
