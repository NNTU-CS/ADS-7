// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM* next;
    ITEM* prev;
  };
  TPQueue::ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
  }
  ITEM* head;
  ITEM* tail;

 public:
  T pop() {
    if (head) {
      ITEM* val = head->next;
    if (val)
      val->prev = nullptr;
    T value = head->value;
    delete head;
    head = val;
    return value;
    } else {
      throw std::string("Empty!");
    }
  }
  void push(const T& value) {
    ITEM* val = head;
    ITEM* item = create(value);
    while (val && val->value.prior >= value.prior)
      val = val->next;
    if (!val && head) {
      tail->next = item;
      tail->next->prev = tail;
      tail = item;
    } else if (!val && !head) {
      head = tail = item;
    } else if (!val->prev) {
      val->prev = item;
      item->next = val;
      head = item;
    } else {
      val->prev->next = item;
      item->prev = val->prev;
      item->next = val;
      val->prev = item;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};


#endif  // INCLUDE_TPQUEUE_H_
