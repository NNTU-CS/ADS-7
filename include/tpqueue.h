// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
  };
  ITEM* head;
 public:
  TPQueue() : head(nullptr) { }
  void push(const T&);
  T pop();
};
struct SYM {
  char ch;
  int prior;
};

template<typename T>
void TPQueue<T>::push(const T& data) {
  if (!head) {
    head = new ITEM;
    head->data = data;
    head->next = nullptr;
  } else if (data.prior > head->data.prior) {
    ITEM* temp = new ITEM;
    temp->data = data;
    temp->next = head;
    head = temp;
  } else {
    ITEM* comp = head;
    while (comp->next) {
      if (data.prior > comp->next->data.prior) {
        ITEM* temp = new ITEM;
        temp->data = data;
        temp->next = comp->next;
        comp->next = temp;
        return;
      }
      comp = comp->next;
    }
    comp->next = new ITEM;
    comp->next->data = data;
    comp->next->next = nullptr;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  if (head) {
    ITEM* temp = head->next;
    T data = head->data;
    delete head;
    head = temp;
    return data;
  } else {
    throw std::string("Empty!");
  }
}

#endif  // INCLUDE_TPQUEUE_H_
