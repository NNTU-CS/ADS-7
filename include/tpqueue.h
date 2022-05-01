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
  ITEM *nt;
  ITEM *pv;
  };

 public:
  T pop();
  void push(const T& value);
  TPQueue():hd(nullptr), tl(nullptr) {}
  ~TPQueue() {
  while (hd)
  pop();
}

 private:
  TPQueue::ITEM *create(const T& value) {
  ITEM *im = new ITEM;
  im->value = value;
  im->nt = nullptr;
  im->pv = nullptr;
  return im;
}
  ITEM *tl;
  ITEM *hd;
};
template<typename T>
  void TPQueue<T>::push(const T& value) {
  ITEM *tp = hd;
  ITEM *im = create(value);
  while (tp && tp -> value.prior >= value.prior)
  tp = tp->nt;
  if (!tp && hd) {
  tl->nt = im;
  tl->nt->pv = tl;
  tl = im;
  } else if (!tp && !hd) {
  hd = tl = im;
  } else if (!tp->pv) {
  tp->pv = im;
  im->nt = tp;
  hd = im;
  } else {
  tp->pv->nt = im;
  im->pv = tp->pv;
  im->nt = tp;
  tp->pv = im;
  }
}
template<typename T>
  T TPQueue<T>::pop() {
  if (hd) {
  ITEM *tp = hd->nt;
  if (tp)
  tp->pv = nullptr;
  T value = hd->value;
  delete hd;
  if (!hd) tl = nullptr;
  hd = tp;
  return value;
  } else {
  throw std::string("It is Empty!");
}
}
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
