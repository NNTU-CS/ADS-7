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
  Item* started;
  Item* del;

 public:
    TPQueue(): started(nullptr), del(nullptr) {}
    void push(const T& value) {
      Item* temp = new Item;
      temp->item = value;
      temp->next = nullptr;
      if (started == nullptr) {
        staredt = temp;
        del = temp;
        return;
      }
      if (started->item.prior < value.prior) {
        temp->next = started;
        started = temp;
        return;
      }
      Item* i = started;
      while (i->next != nullptr && i->next->item.prior >= value.prior)
        i = i->next;
      temp->next = i->next;
      i->next = temp;
      if (temp->next == nullptr)
        del = temp;
    }
    const T pop() {
      Item* temp = started;
      T Res = temp->item;
      started = started->next;
      delete temp;
      return Res;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
