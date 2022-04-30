// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T value;
    Item* next;
    Item* prev;
  };
  Item* head = nullptr, * tail = nullptr;
  TPQueue<T>::Item* create(T value) {
    Item* item = new Item;
    item->value = value;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
  }

 public:
  void push(T value) {
    Item* temp = create(value);
    if (head && tail) {
      if ((head->value.prior) < (temp->value.prior)) {
        head->prev = temp;
        temp->next = head;
        head = temp;
      } else if ((tail->value.prior) >= (temp->value.prior)) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
      } else {
        Item* temphead = head;
        while (true) {
          if ((temphead->next->value.prior) < (temp->value.prior)) {
            temp->next = temphead->next;
            temp->prev = temphead;
            temphead->next = temp;
            break;
          }
          temphead = temphead->next;
        }
      }
    } else {
        head = tail = create(value);
    }
  }
  T pop() {
    Item* temp = head->next;
    T value = head->value;
    delete head;
    head = temp;
    return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
