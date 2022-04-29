// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM* next;
  };
  ITEM* head;
  ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = nullptr;
    return item;
  }

 public:
  TPQueue() : head(nullptr) { }
  void push(const T& item) {
    if (!head) {
      head = create(item);
      return;
    }
    if (item.prior > head->value.prior) {
      ITEM* nitem = create(item);
      nitem->next = head;
      head = nitem;
      return;
    }
    ITEM* temp = head;
    while (temp->next) {
      if (item.prior > temp->next->value.prior) {
        ITEM* nitem = create(item);
        nitem->next = temp->next;
        temp->next = nitem;
        return;
      }
      temp = temp->next;
    }
    temp->next = create(item);
  }
  T pop() {
    ITEM* nhead = head->next;
    T tmp = head->value;
    delete head;
    head = nhead;
    return tmp;
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
