// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
  T data;
  Item* next;
  };
  Item* head;
  Item* tail;
  int cnt = 0;

 public:
  TPQueue() : head(nullptr), tail(nullptr) {}
  void push(const T& value) {
    int prioritet = value.prior;
    Item* temp = new Item;
    temp->data = value;
    temp->next = nullptr;
    if (head == nullptr) {
      head = temp;
      tail = temp;
      cnt++;
      return;
    }
    if (head->data.prior < prioritet) {
      temp->next = head;
      head = temp;
      cnt++;
      return;
    }
    Item* end = head;
    for (int i = cnt - 1; i > 0; i--)
      if (end->next != nullptr && end->next->data.prior >= prioritet)
        end = end->next;
    temp->next = end->next;
    end->next = temp;
    if (temp->next == nullptr)
      tail = temp;
  }
  const T pop() {
    Item* temp = head;
    T res = temp->data;
    head = head->next;
    delete temp;
    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
