// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T value;
    Item * next;
    Item * prev;
  };
  TPQueue :: Item * creat(const T& value) {
    Item * item = new Item;
    item -> value = value;
    item -> next = nullptr;
    item -> prev = nullptr;
    return item;
  }
  Item * head, * tail, * current;

 public:
  TPQueue(): head(nullptr), tail(nullptr) {}
  void push(const T& value) {
    Item * h = head;
    Item * v = creat(value);
    while (h && h -> value.prior >= value.prior) {
      h = h -> next;
    }
    if (!h && head) {
      tail -> next = v;
      v -> prev = tail;
      tail = v;
    } else if (!h && !head) {
      head = tail = v;
    } else if (!h -> prev) {
      head -> prev = v;
      v ->  next = head;
      head = v;
    } else {
      h -> prev -> next = v;
      v -> prev = h -> prev;
      h -> prev = v;
      v -> next = h;
    }
  }

  T pop() {
    T value = head -> value;
    if (head && tail) {
      if (head) {
        Item* zam = head -> next;
        if (zam) {
          zam -> prev  = nullptr;
        }
        delete head;
        head = zam;
      } else {
        tail = nullptr;
      }
    }
  return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
