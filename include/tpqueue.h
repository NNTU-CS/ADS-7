// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
  };
  ITEM* head;
  ITEM* tail;

  ITEM* create(const T& a) {
    ITEM* temp = new ITEM;
    temp->data = a;
    temp->next = nullptr;
    return temp;
  }

 public:
  TPQueue() : head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& a) {
    ITEM* temp = create(a);
    if (head == nullptr) {
      head = temp;
      tail = temp;
    } else {
      if (a.prior > head->data.prior) {
        temp->next = head;
        head = temp;
      } else {
        ITEM* f = head;
        while (f->next != nullptr && f->next->data.prior >= a.prior) {
          f = f->next;
        }
        temp->next = f->next;
        f->next = temp;
        if (temp->next == nullptr)
          tail = temp;
      }
    }
  }

  T pop() {
    ITEM* temp = head;
    T res = temp->data;
    head = head->next;
    delete temp;
    return res;
  }

  bool isEmpty() const {
    return !head;
  }
};



#endif  // INCLUDE_TPQUEUE_H_
