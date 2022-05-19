// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue {
 private:
  struct ITEM {
        T value;
        ITEM* next;
        ITEM* last;
  };
  ITEM* head;
  ITEM* tail;
    ITEM* create(T value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = nullptr;
    item->last = nullptr;
    return item;
}

 public:
  T pop() {
ITEM* num = head->next;
if (num) {
    num->last = nullptr;
    }
T value = head->value;
delete head;
head = num;
return value;
  }


    TPQueue() :head(nullptr), tail(nullptr) {}
    void push(T value) {
      ITEM* num = head;
      ITEM* item = create(value);
      while (num && num->value.prior >= value.prior)
        num = num->next;
      if (!num && head) {
        tail->next = item;
        tail->next->last = tail;
        tail = item;
      } else if (!num && !head) {
        head = tail = item;
      } else if (!num->last) {
        num->last = item;
        item->next = num;
        head = item;
      } else {
        num->last->next = item;
        item->last = num->last;
        item->next = num;
        num->last = item;
      }
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
