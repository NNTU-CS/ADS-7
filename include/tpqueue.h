// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
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
    return head == nullptr;
  }
  Item* head;
  Item* tail;
  Item* current;

 public:
  TPQueue() {
    head = tail = current = nullptr;
 }
  ~TPQueue() {
    if (IsEmpty()) {
      return;
    } else if (head->next) {
      current = head->next;
      while (current != tail) {
        delete current->prev;
        current = current->next;
      }
      delete tail;
    } else {
      delete head;
    }
  }
  void push(T sym) {
    if (IsEmpty()) {
      head = tail = create(sym);
    } else {
      Item* temp = create(sym);
      current = head;
      if (sym.prior <= head->data.prior && sym.prior > tail->data.prior) {
        while (sym.prior <= current->data.prior) {
          current = current->next;
	}
        current = current->prev;
        temp->prev = current;
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
      } else if (sym.prior > head->data.prior) {
        temp->next = head;
        head->prev = temp;
        head = temp;
      } else {
        tail->next = temp;
        tail->next->prev = tail;
        tail = tail->next;
      }
    }
  }
  T pop() {
    if (head && tail) {
      Item* temp = head->next;
      if (head->next != nullptr) {
        temp->prev = nullptr;
      }
      T data = head->data;
      delete head;
      head = temp;
      if (head == nullptr)
        tail = nullptr;
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
