// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
  struct Item {
    T data;
    Item* next = nullptr;
    Item* prev = nullptr;
  };
  Item* create(const T& data) {
    Item* item = new Item;
    item->data = data;
    return item;
  }
  bool IsEmpty() {
    return start == nullptr;
  }
  Item* start;
  Item* finish;
  Item* temp;

 public:
  TPQueue() {
    start = finish = temp = nullptr;
  }
  ~TPQueue() {
    if (IsEmpty()) {
      return;
    } else if (start->next) {
      temp = start->next;
      while (temp != finish) {
        delete temp->prev;
        temp = temp->next;
      }
      delete finish;
    } else {
      delete start;
    }
  }
  void push(T sym) {
    if (IsEmpty()) {
      start = finish = create(sym);
    } else {
      Item* temp_item = create(sym);
      temp = start;
      if (sym.prior <= start->data.prior && sym.prior > finish->data.prior) {
        while (sym.prior <= temp->data.prior) {
          temp = temp->next;
        }
        temp = temp->prev;
        temp_item->prev = temp;
        temp_item->next = temp->next;
        temp->next->prev = temp_item;
        temp->next = temp_item;
      } else if (sym.prior > start->data.prior) {
        temp_item->next = start;
        start->prev = temp_item;
        start = temp_item;
      } else {
        finish->next = temp_item;
        finish->next->prev = finish;
        finish = finish->next;
      }
    }
  }
  T pop() {
    if (start && finish) {
      temp = start->next;
      if (start->next != nullptr) {
        temp->prev = nullptr;
      }
      T data = start->data;
      delete start;
      start = temp;
      if (start == nullptr)
        finish = nullptr;
      return data;
    } else {
      T fake{'0', -10};
      return fake;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
