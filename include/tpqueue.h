// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct node {
        SYM data;
        node* next;
    };
    node* head;
 public:
    TPQueue() : head(nullptr) {}
    void push(SYM newSym) {
      node* newNode = new node{ newSym, nullptr };
      if (head == nullptr || newSym.prior > head->data.prior) {
        newNode->next = head;
        head = newNode;
      } else {
        node* tmp = head;
        while (tmp->next != nullptr &&
        while (tmp->next != nullptr &&
          newSym.prior <= tmp->next->data.prior) {
          tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
      }
}
SYM pop() {
  if (head == nullptr) {
    return SYM{ '0', 0 };
  }
  SYM last = head->data;
  node* tmp = head;
  head = head->next;
  delete tmp;
  return last;
}
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
