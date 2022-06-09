// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T tim;
    ITEM* next;
  };
  ITEM* head;
  ITEM* tail;
  TPQueue::ITEM* create(const T& value) {
    ITEM* i = new ITEM;
    i->tim = value;
    i->next = nullptr;
    return i;
  }

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  T pop() {
    if (head) {
      ITEM* temp = head;
      head = head->next;
      return temp->tim;
    }
    T value;
    value.prior = 0;
    value.ch = ' ';
    return value;
  }
  void push(T value) {
    ITEM* tmp = nullptr;
    ITEM* i = create(value);
    ITEM* temp = head;
    if (head && tail) {
       while (temp && (temp->tim).prior >= value.prior) {
         tmp = temp;
         temp = temp->next;
       }
       if (temp == head && ((head->tim).prior == (i->tim).prior)) {
         i->next = head->next;
         head->next = i;
       } else if (temp == head && ((head->tim).prior >= (i->tim).prior)) {
         i->next = head->next;
         head->next = i;
       } else if (temp == head && ((head->tim).prior < (i->tim).prior)) {
         i->next = head;
         head = i;
       } else if (!temp) {
         tail->next = i;
         tail = i;
       } else {
         tmp->next = i;
         i->next = temp;
       }
    } else {
      head = create(value);
      tail = head;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
