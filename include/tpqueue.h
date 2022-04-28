// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private :
  struct ITEM {
    T content;
    ITEM * next;
    ITEM* prev;
  };
  TPQueue :: ITEM * create(const T &);
  ITEM* head;
  ITEM* end;
 public:
  TPQueue():head(nullptr), end(nullptr) {}
  void push(const T&);
  T pop();
};

struct SYM {
  char ch;
  int pr;
};
template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& content) {
  ITEM * item = new ITEM;
  item -> content = content;
  item -> next = nullptr;
  item -> prev = nullptr;
  return item;
}
template < typename T >
void TPQueue <T>::push(const T& content) {
  ITEM * tmp = head;
  ITEM * item = create(content);
  while (tmp && tmp -> content.pr >= content.pr )
    tmp = tmp -> next;
  if (!tmp && head) {
    end -> next = item;
    end -> next -> prev = end;
    end = item;
  } else if (!tmp && !head) {
      head = tail = item;
  } else if (!tmp -> prev) {
    tmp -> prev = item;
    item -> next = tmp;
    head = item;
  } else {
      tmp -> prev -> next = item;
      item -> prev = tmp -> prev;
      item -> next = tmp;
      tmp -> prev = item;
  }
}
template < typename T >
T TPQueue<T>::pop() {
  ITEM * tmp = head -> next;
  if (tmp)
    tmp -> prev = nullptr;
  T content = head -> content;
  delete head;
  head = tmp;
  return content;
}
#endif  // INCLUDE_TPQUEUE_H_
