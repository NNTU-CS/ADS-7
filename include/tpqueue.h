// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
  struct Elem {
    T data;
    Elem* prev = nullptr;
    Elem* next = nullptr;
  };
  Elem* create(const T& data) {
    Elem* elem = new Elem;
    elem->data = data;
    return elem;
  }
  bool Empty() {
    return begin == nullptr;
  }
  Elem* begin;
  Elem* end;
  Elem* perem;

 public:
  TPQueue() {
    begin = end = perem = nullptr;
  }
  ~TPQueue() {
    if (Empty()) {
      return;
    } else if (begin->next) {
      perem = begin->next;
      while (perem != end) {
        delete perem->prev;
        perem = perem->next;
      }
      delete end;
    } else {
      delete begin;
    }
  }
  void push(T sym) {
    if (Empty()) {
      begin = end = create(sym);
    } else {
      Elem* peremElem = create(sym);
      perem = begin;
      if (sym.prior <= begin->data.prior && sym.prior > end->data.prior) {
        while (sym.prior <= perem->data.prior) {
          perem = perem->next;
        }
        perem = perem->prev;
        peremElem->prev = perem;
        peremElem->next = perem->next;
        perem->next->prev = peremElem;
        perem->next = peremElem;
      } else if (sym.prior > begin->data.prior) {
        peremElem->next = begin;
        begin->prev = peremElem;
        begin = peremElem;
      } else {
        end->next = peremElem;
        end->next->prev = end;
        end = end->next;
      }
    }
  }
  T pop() {
    if (begin && end) {
      perem = begin->next;
      if (begin->next != nullptr) {
        perem->prev = nullptr;
      }
      T data = begin->data;
      delete begin;
      begin = perem;
      if (begin == nullptr)
        end = nullptr;
      return data;
    } else {
      T fake{'0', -10};
      return fake;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
