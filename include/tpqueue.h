// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
  struct Item {
    T data;
    Item* next;
    int prior;
  };
  Item* head;
  Item* tail;
  
 public:
  TPQueue(): head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head) {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
  }

  void push(const SYM& val) {
    Item* newV = new Item;
    newV->data = val;
    newV->next = nullptr;
    newV->prior = val.prior;

    if (head == nullptr) {
      head = newV;
      tail = newV;
    } else {
      if (val.prior > head->prior) {
        temp->next = head;
        head = newV;
      } else {
        Item temp = head;
        while (temp->next && val.prior <= temp->next->prior) {
          temp = temp->next;
        }
        newV->next = temp->next;
        temp->next = newV;
        if (!newV->next) {
          tail = newV;
        }
      }
    }
  }

  T pop() {
    T data = head->data;
    Item* temp = head;
    head = head->next;
    delete temp;
    return data;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
