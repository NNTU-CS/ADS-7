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
  Item* head, tail;
  TPQueue::Item create(const T& value) {
    Item* item = new Item;
    item->data = value;
    item->next = nullptr;
    return item;
  }
 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  T pop() {
    if (head) {
      Item* temp = head;
      head = head->next;
      return temp->data;
    } else {
      return (T)0;
    }
  }
  void push(T value) {
    Item* tmp = nullptr;
    Item* item = create(value);
    Item* temp = head;
    while (temp && (temp->data).prior >= value.prior) {
      tmp = temp;
      temp = temp->next;
    }
    if (temp == head && ((head->data).prior == (item->data).prior)) {
      item->next = head->next;
      head->next = item;
    } else if (temp == head && ((head->data).prior >= (item->data).prior)) {
      item->next = head->next;
      head->next = item;
    } else if (temp == head && ((head->data).prior < (item->data).prior)) {
      item->next = head;
      head = item;
    } else if (!temp) {
      tail->next = item;
      tail = item;
    } else {
      tmp->next = item;
      item->next = temp;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
