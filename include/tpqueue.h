// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
  T value;
  ITEM *n;
  ITEM *p;
  };

 public:
  T pop();
  void push(const T& value);
  TPQueue():hea(nullptr), tai(nullptr) {}
  ~TPQueue() {
  while (hea) {
  pop();
  }
  }

 private:
  TPQueue::ITEM *c(const T& value) {
  ITEM *it = new ITEM;
  it -> value = value;
  it -> n = nullptr;
  it -> p = nullptr;
  return it;
  }
  ITEM *tai;
  ITEM *hea;
};
template<typename T>
  void TPQueue<T>::push(const T& value) {
  ITEM *t = hea;
  ITEM *it = c(value);
  while (t && t -> value.prior >= value.prior)
  t = t -> n;
  if (!t && hea) {
  tai->n = it;
  tai->n->p = tai;
  tai = it;
  } else if (!t && !hea) {
  hea = tai = it;
  } else if (!t->p) {
  t->p = it;
  it->n = t;
  hea = it;
  } else {
  t->p->n = it;
  it->p = t->p;
  it->n = t;
  t->p = it;
  }
}
template<typename T>
T TPQueue<T>::pop() {
if (hea) {
ITEM *t = hea->n;
if (t)
t->p = nullptr;
T value = hea->value;
delete hea;
if (!hea) tai = nullptr;
hea = t;
return value;
} else {
throw std::string("Empty!");
}
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
