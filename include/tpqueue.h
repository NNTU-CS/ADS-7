// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

struct SYM {
  char ch;
  int prior;
};

template <typename T>
class TPQueue {
private:
  struct list {
    T name;
    list* next;
  };
  list* head;
  list* tail;

  list* create(const T& c) {
    list* t = new list;
    t->name = c;
    t->next = nullptr;
    return t;
  }

public:
  TPQueue() : head(nullptr), tail(nullptr) {};
  void push(const T& c) {
    list* t = create(c);
    if (head == nullptr) {
      head = t;
      tail = t;
    } else {
      if (c.prior > head->name.prior) {
        t->next = head;
        head = t;
      } else {
        list* f = head;
        while (f->next != nullptr && f->next->name.prior >= c.prior) {
          f = f->next;
        }
        t->next = f->next;
        f->next = t;
        if (t->next == nullptr) tail = t;
      }
    }
  }
  const T pop() {
    list* t = head;
    T res = t->name;
    head = head->next;
    delete t;
    return res;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
};

#endif // INCLUDE_TPQUEUE_H_
