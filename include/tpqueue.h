// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  struct item {
    T w;
    item *next;
  };

 private:
  item *head;
  item *tail;
  item *create(T w) {
    item *bill = new item;
    bill->w = w;
    bill->next = nullptr;
    return bill;
  }

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }
  T pop() {
    item *a = head->next;
    T w = head->w;
    delete head;
    head = a;
    return w;
  }
  void push(const T &w) {
    if (!tail || !head) {
      head = create(w);
      tail = head;
    } else {
        item *a = head;
        if (a->w.prior < w.prior) {
          a = create(w);
          a->next = head;
          head = a;
        } else {
            while (a->next) {
              if (a->next->w.prior < w.prior) {
                item *bill = create(w);
                bill->next = a->next;
                a->next = bill;
                break;
              } else {
                  a = a->next;
                }
              }
            }
            if (!a->next) {
              tail->next = create(w);
              tail = tail->next;
            }
          }
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
