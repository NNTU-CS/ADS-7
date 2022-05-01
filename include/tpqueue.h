// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM * next;
    ITEM * prev;
  };
  ITEM* head, * tail;
  TPQueue::ITEM* create(const T& value);

 public:
  TPQueue():head(nullptr), tail(nullptr) {}
  void push(const T&);
  T pop();
};

template<typename T>
typename TPQueue<T>::ITEM * TPQueue<T>::create(const T& value) {
  ITEM * item = new ITEM;
  item -> value = value;
  item -> next = nullptr;
  item -> prev = nullptr;
  return item;
}

template<typename T>
void TPQueue <T>::push(const T& value) {
  ITEM * temp = head;
  ITEM * item = create(value);
  while (temp && temp -> value.prior >= value.prior)
    temp = temp -> next;
  if (!temp && head) {
    tail -> next = item;
    tail -> next -> prev = tail;
    tail = item;
  } else if (!(temp || head)) {
    head = tail = item;
  } else if (!temp -> prev) {
    temp -> prev = item;
    item -> next = temp;
    head = item;
  } else {
    temp -> prev -> next = item;
    item -> prev = temp -> prev;
    item -> next = temp;
    temp -> prev = item;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  ITEM * temp = head -> next;
  if (temp) {
    temp -> prev = nullptr;
  }
  T value = head -> value;
  delete head;
  head = temp;
  return value;
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
