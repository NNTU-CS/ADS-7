// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
     T znach;
     ITEM* next;
  };
  ITEM* first, *last;
 public:
  TPQueue();
  void push(T nznach);
  T pop();
};

template <typename T>
TPQueue<T>::TPQueue() {
  first, last = 0;
}

template <typename T>
void TPQueue<T>::push(T nznach) {
  ITEM* last = first;
  if (!last) {
    last = new ITEM;
    first = last;
    last -> znach = nznach;
    last -> next = nullptr;
  } else {
    ITEM* t = new ITEM;
    t -> znach = nznach;
    if (first -> znach.prior < t -> znach.prior) {
      t -> next = last;
      first = t;
    }
    while (last != nullptr) {
      if ((last -> znach.prior == t -> znach.prior &&
           (last -> next == nullptr ||
            last -> next -> znach.prior < t -> znach.prior)) ||
          (last -> znach.prior > t -> znach.prior &&
           ((last -> next != nullptr &&
             last -> next -> znach.prior < t -> znach.prior) ||
            (last -> next == nullptr)))) {
        t -> next = last -> next;
        last -> next = t;
        return;
      }
      last = last->next;
    }
  }
}

template <typename T>
T TPQueue<T>::pop() {
  ITEM* t = first;
  first = first -> next;
  return (t -> znach);
}
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
