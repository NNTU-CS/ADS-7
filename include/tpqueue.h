// Copyright 2022 DegtyarevPaul
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T sym;
    ITEM* next;
  };
  TPQueue::ITEM* create(const T& value) {
    ITEM* p = new ITEM;
    p->sym = value;
    p->next = nullptr;
    return p;
  }
  ITEM* head;

 public:
  TPQueue() :head(nullptr) {}
  T pop() {
    ITEM* temp = head;
    head = head->next;
    return temp->sym;
  }
  void push(T value) {
    if (head) {
      ITEM* th = create(value);
      if (value.prior > head->sym.prior) {
        th->next = head;
        head = th;
        return;
      }
      ITEM* temp = head;
      while (temp->next) {
      if (value.prior > temp->next->sym.prior) {
        th = create(value);
        th->next = temp->next;
        temp->next = th;
        return;
      }
        temp = temp->next;
    }
    temp->next = create(value);
    } else {
      head = create(value);
      return;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
