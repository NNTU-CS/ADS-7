// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* dal;
  };
  Item* start;
  Item* end;
  int count = 0;

 public:
  TPQueue() : start(0), end(0) {}
  void push(const T& value) {
    int pr = value.prior;
    Item* temp = new Item;
    temp->data = value;
    temp->dal = 0;
    if (start == 0) {
      start = temp;
      end = temp;
      count++;
      return;
    }
    if (start->data.prior < pr) {
      temp->dal = start;
      start = temp;
      count++;
      return;
    }
    Item* tail = start;
    for (int i = count-1; i > 0; i--)
      if (tail->dal != 0 && tail->dal->data.prior >= pr)
        tail = tail->dal;
    temp->dal = tail->dal;
    tail->dal = temp;
    if (temp->dal == 0)
      end = temp;
  }
  const T pop() {
    Item* temp = start;
    T res = temp->data;
    start = start->dal;
    delete temp;
    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
