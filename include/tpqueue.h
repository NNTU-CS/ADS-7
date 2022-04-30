// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue{
 private:
  struct ITEM {
     T value;
     ITEM* next;
  };
  ITEM* first, * last;

 public:
  TPQueue();
  void push(T _val);
  T pop();
};

template <typename T>
TPQueue<T>::TPQueue() {
  first = 0;
  last = 0;
}

template <typename T>
void TPQueue<T>::push(T _val) {
  ITEM* last = first;
  if (!last) {
    last = new ITEM;
    first = last;
    last -> value = _val;
    last -> next = nullptr;
  } else {
    ITEM* t = new ITEM;
    t -> value = _val;
    if (first -> value.prior < t -> value.prior) {
      t -> next = last;
      first = t;
    }
    while (last != nullptr) {
      if ((last -> value.prior == t -> value.prior &&
           (last -> next == nullptr ||
            last -> next -> value.prior < t -> value.prior)) ||
          (last -> value.prior > t -> value.prior &&
           ((last -> next != nullptr &&
             last -> next -> value.prior < t -> value.prior) ||
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
  return (t -> value);
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
