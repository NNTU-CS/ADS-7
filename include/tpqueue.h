// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T val;
        ITEM* next;
        ITEM* prev;
    };
  ITEM* head;
  ITEM* tail;

    ITEM* create(T val) {
    ITEM* item = new ITEM;
    item->val = val;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}

 public:
    TPQueue() :head(nullptr), tail(nullptr) {}

    void push(T val) {
      ITEM* cur = head;
      ITEM* item = create(val);
      while (cur && cur->val.prior >= val.prior)
        cur = cur->next;
      if (!cur && head) {
        tail->next = item;
        tail->next->prev = tail;
        tail = item;
      } else if (!cur && !head) {
        head = tail = item;
      } else if (!cur->prev) {
        cur->prev = item;
        item->next = cur;
        head = item;
      } else {
        cur->prev->next = item;
        item->prev = cur->prev;
        item->next = cur;
        cur->prev = item;
      }
  }
  T pop() {
    ITEM* cur = head->next;
    if (cur) {
      cur->prev = nullptr;
    }
    T val = head->val;
    delete head;
    head = cur;
    return val;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
