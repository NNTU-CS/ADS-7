// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
  struct ITEM {
    T data;
    ITEM* next, * prev;
  };
  ITEM* head, * tail;
  TPQueue::ITEM* createv(const T& data, ITEM* prev) {
    ITEM* item = new ITEM;
    item->data = data;
    item->next = nullptr;
    item->prev = prev;
    return item;
  }

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }
  void push(const T& data) {
    if (tail && head) {
      ITEM* uni = tail;
      while (uni && data.prior > (uni->data).prior) {
        uni = uni->prev;
      }
      if (uni) {
        ITEM* lat = uni->next;
        uni->next = createv(data, uni);
        uni = uni->next;
        uni->next = lat;
        if (lat)
          lat->prev = uni;
        else
          tail = uni;
      } else {
        uni = createv(data, nullptr);
        uni->next = head;
        head->prev = uni;
        head = uni;
      }
    } else {
      head = createv(data, nullptr);
      tail = head;
    }
  }
  T pop() {
    assert(head);
    ITEM* lat = head->next;
    T data = head->data;
    if (lat)
      lat->prev = nullptr;
    delete head;
    head = lat;
    return data;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
