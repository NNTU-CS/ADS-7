// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* d;
  };
  Item* start;
  Item* end;
  int c = 0;

 public:
  TPQueue() : start(nullptr), end(nullptr) {}
  const T pop() {
    Item* temp = start;
    T result = temp->data;
    start = start->d;
    delete temp;
    return result;
  }
  void push(const T& value) {
    int pr = value.prior;
    Item* temp = new Item;
    temp->data = value;
    temp->d = nullptr;
    if (start == nullptr) {
      start = temp;
      end = temp;
      c++;
      return;
    }
    if (start->data.prior < pr) {
      temp->d = start;
      start = temp;
      c++;
      return;
    }
    Item* tail = start;
    for (int i = c-1; i > 0; i--)
      if (tail->d != nullptr && tail->d->data.prior >= pr)
        tail = tail->d;
    temp->d = tail->d;
    tail->d = temp;
    if (temp->d == nullptr)
      end = temp;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
