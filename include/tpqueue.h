// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T value;
    ITEM* next;
    ITEM* prev;
  };
  ITEM* head, * tail, * current;
  TPQueue::ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item->value = value;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
  }

 public:
  TPQueue() {
    head = tail = nullptr;
    current = nullptr;
  }
  ~TPQueue() {
    while (head) {
      rmHead();
    }
  }

  void push(const T& value) {
    ITEM* temp = head;
    ITEM* item = create(value);
    while (temp && temp->value.prior >= item->value.prior) {
      temp = temp->next;
    }
    if (!temp && head) {
      tail->next = item;
      tail->next->prev = tail;
      tail = tail->next;
    } else if (!temp && !head) {
      head = tail = item;
    } else if (!temp->prev) {
      head->prev = item;
      head->prev->next = head;
      head = head->prev;
    } else {
      temp->prev->next = item;
      item->prev = temp->prev;
      item->next = temp;
      temp->prev = item;
    }
  }

  bool isEmpty() const {
    return !head;
  }

  void addHead(const T& value) {
    if (head && tail) {
      head->prev = create(value);
      head->prev->next = head;
      head = head->prev;
    } else {
      head = tail = create(value);
    }
  }

  void addTail(const T& value) {
    if (head && tail) {
      tail->next = create(value);
      tail->next->prev = tail;
      tail = tail->next;
    } else {
      head = tail = create(value);
    }
  }

  T rmHead() {
    if (head && tail) {
      ITEM* temp = head->next;
      if (temp) {
        temp->prev = nullptr;
      }
      T value = head->value;
      delete head;
      head = temp;
      if (!head) {
        tail = nullptr;
      }
      return value;
    } else {
      throw "UPS";
    }
  }

  T rmTail() {
    if (head && tail) {
      ITEM* temp = tail->prev;
      if (temp) {
        temp->next = nullptr;
      }
      T value = tail->value;
      delete tail;
      tail = temp;
      if (!tail) {
        head = nullptr;
      }
      return value;
    } else {
      throw "UPS";
    }
  }

  T pop() {
    if (isEmpty()) {
      throw "Sorry, it`s empty!!!";
    } else {
      return rmHead();
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
