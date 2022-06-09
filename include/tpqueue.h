// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 public:
      TPQueue(): head(nullptr), tail(nullptr) {}
      void push(const T&);
      T pop();
 private:
      struct ITEM {
          T value;
          ITEM *next;
          ITEM *prew;
      };
      TPQueue:: ITEM *create(const T&);
      ITEM *head;
      ITEM *tail;
};

template<typename T>
typename TPQueue<T>::ITEM *TPQueue<T>::create(const T& value) {
  ITEM * temp = new ITEM;
  temp->value = value;
  temp->next = nullptr;
  temp->prew = nullptr;
  return temp;
}

template<typename T>
void TPQueue <T>::push(const T& data) {
  ITEM *temp = head;
  ITEM* item = create(data);
  while (temp && temp->value.prior >= data.prior) {
    temp = temp->next;
  }
  if (!temp && head) {
    tail ->next = item;
    item->prew = tail;
    tail = item;
  } else if (!temp && !head) {
    head = tail = item;
  } else if (!temp->prew) {
    head->prew = item;
    item->next = head;
    head = item;
  } else {
    temp->prew->next = item;
    item->prew = temp->prew;
    item->next = temp;
    temp->prew = item;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  if (head && tail) {
    ITEM* temp = head->next;
    if (temp) {
      temp->prew = nullptr;
    }
    T data = head->value;
    delete head;
    head = temp;
    if (!head) {
      tail = nullptr;
    }
    return data;
  } else {
    throw std::string("Is Empty!");
  }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
