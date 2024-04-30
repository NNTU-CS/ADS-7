// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T>
class TPQueue {
 private:
  struct Elem {
    Elem* next = nullptr;
    Elem* prev = nullptr;
    T data;
  };

  Elem* first = nullptr;
  Elem* last = nullptr;

 public:
  void push(T new_elem) {
    Elem* elem = new Elem;
    elem->data = new_elem;

    if (first == nullptr) {
      first = elem;
      last = elem;
      print();
      return;
    }

    Elem* before_elem = last;
    Elem* after_elem = nullptr;
    while ((before_elem != nullptr) &&
           (before_elem->data.prior < elem->data.prior)) {
      after_elem = before_elem;
      before_elem = before_elem->prev;
    }
    elem->prev = before_elem;
    elem->next = after_elem;

    if (after_elem) {
      after_elem->prev = elem;
    } else {
      last = elem;
    }

    if (before_elem) {
      before_elem->next = elem;
    } else {
      first = elem;
    }
  }

  T pop() {
    T res = first->data;
    Elem* after_1 = first->next;
    if (after_1) {
      after_1->prev = nullptr;
    }
    delete first;
    first = after_1;

    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
