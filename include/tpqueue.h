// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
  };
  ITEM* head, tail;
  TPQueue::Item* create(const T& value) {
    ITEM* it = new Item;
    it->data = value;
    it->next = nullptr;
    return it;
  }
 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  T pop() {
    if (head) {
      ITEM* temp = head;
      head = head->next;
      return temp->data;
    } else {
      return 0;
    }
  }
  void push(T value) {
    ITEM* tmp = nullptr;
    ITEM* it = create(value);
    ITEM* temp = head;
    while (temp && (temp->data).prior >= value.prior) {
      tmp = temp;
      temp = temp->next;
    }
    if (temp == head && ((head->data).prior == (it->data).prior)) {
      it->next = head->next;
      head->next = it;
    } else if (temp == head && ((head->data).prior >= (it->data).prior)) {
      it->next = head->next;
      head->next = item;
    } else if (temp == head && ((head->data).prior < (it->data).prior)) {
      it->next = head;
      head = it;
    } else if (!temp) {
      tail->next = it;
      tail = it;
    } else {
      tmp->next = it;
      it->next = temp;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
