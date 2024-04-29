// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
private:
  struct Item {
    T data;
    Item* coming;
  };
  Item* start;
  Item* finish;
  int count = 0;

 public:
  TPQueue() : start(nullptr), finish(nullptr) {}
  void push(const T& val) {
    int prior = val.prior;
    Item* temp = new Item;
    temp->data = val;
    temp->coming = nullptr;
    if (start == nullptr) {
      start = temp;
      finish = temp;
      count++;
      return;
    }
    if (start->data.prior < prior) {
      temp->coming = start;
      start = temp;
      count++;
      return;
    }
    Item* end = start;
    for (int l = count-1; l > 0; l--)
      if (end->coming != nullptr && end->coming->data.prior >= prior)
        end = end->coming;
    temp->coming = end->coming;
    end->coming = temp;
    if (temp->coming == nullptr)
      finish = temp;
  }
  const T pop() {
    Item* temp = start;
    T finding = temp->data;
    start = start->coming;
    delete temp;
    return finding;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
