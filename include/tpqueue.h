// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T item;
    Item* next;
  };
  Item* head;
  Item* tail;

 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    void push(const T& value) {
      Item* temp = new Item;
      temp->item = value;
      temp->next = nullptr;
      if (head == nullptr) {
        head = temp;
        tail = temp;
        return;
      }
      if (head->item.prior < value.prior) {
        temp->next = head;
        head = temp;
        return;
      }
      Item* i = head;
      while (i->next != nullptr && i->next->item.prior >= value.prior)
        i = i->next;
      temp->next = i->next;
      i->next = temp;
      if (temp->next == nullptr)
        tail = temp;
    }
    const T pop() {
      Item* temp = head;
      T res = temp->item;
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
