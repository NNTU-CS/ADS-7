// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
      struct ITEM {
          T data;
          ITEM *next;
          ITEM *prev;
      };
      TPQueue:: ITEM *create(const T&);
      ITEM *head;
      ITEM *tail;
 public:
      TPQueue(): head(nullptr), tail(nullptr) {}
      T pop();
      void push(const T&);
};

template<typename T>
typename TPQueue<T>::ITEM *TPQueue<T>::create(const T& data) {
  ITEM * temp = new ITEM;
  temp->data = data;
  temp->next = nullptr;
  temp->prev = nullptr;
  return temp;
}

template<typename T>
void TPQueue <T>::push(const T& data) {
  ITEM *temp = head;
  ITEM* item = create(data);
  while (temp && temp->data.prior >= data.prior) {
    temp = temp->next;
  }
  if (!temp && head) {
    tail ->next = item;
    item->prev = tail;
    tail = item;
  } else if (!temp && !head) {
    head = tail = item;
  } else if (!temp->prev) {
    head->prev = item;
    item->next = head;
    head = item;
  } else {
    temp->prev->next = item;
    item->prev = temp->prev;
    item->next = temp;
    temp->prev = item;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  if (head && tail) {
    ITEM* temp = head->next;
    if (temp)
      temp->prev = nullptr;
    T data = head->data;
    delete head;
    head = temp;
    if (!head)
      tail = nullptr;
    return data;
  } else { throw std::string("Empty!"); }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
