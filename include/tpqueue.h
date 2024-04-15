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
      Item* It = head;
      while (It->next != nullptr && It->next->item.prior >= value.prior)
        It = It->next;
      temp->next = It->next;
      It->next = temp;
      if (temp->next == nullptr)
        last = temp;
    }
    const T pop() {
      Item* temp = head;
      T otv = temp->item;
      head = head->next;
      delete temp;
      return otv;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
