// Copyright 2022 NNTU-CS
#include <iostream>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct El {
    El* next = nullptr;
    El* prev = nullptr;
    T data;
  };

  El* first = nullptr;
  El* last = nullptr;

 public:
  void push(T new_el) {
    El* el = new El;
    el->data = new_el;

    if (first == nullptr) {
      first = el;
      last = el;
      return;
    }

    El* before_el = last;
    El* after_el = nullptr;
    while ((before_el != nullptr) &&
           (before_el->data.prior < el->data.prior)) {
      after_el = before_el;
      before_el = before_el->prev;
    }
    el->prev = before_el;
    el->next = after_el;

    if (after_el) {
      after_el->prev = el;
    } else {
      last = el;
    }

    if (before_el) {
      before_el->next = el;
    } else {
      first = el;
    }
  }

  T pop() {
    T res = first->data;
    El* after_1 = first->next;
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
