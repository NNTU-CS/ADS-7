// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>

class TPQueue{
 private:
struct ITEM {
    T value;
    ITEM* next;
};
ITEM* head;
ITEM* tail;

 public:
    TPQueue() :head(nullptr), tail(nullptr) {}

T pop() {
    ITEM* temp = head;
    head = head->next;
    return (temp->value);
}

void push(T symb) {
    ITEM* tail = head;
    if (tail == nullptr) {
        tail = new ITEM;
        head = tail;
        tail->value = symb;
        tail->next = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->value = symb;
        if (head->value.prior < elm->value.prior) {
            elm->next = tail;
            head = elm;
        }
        while (tail != nullptr) {
        if ((tail->value.prior == elm->value.prior &&
           (tail->next == nullptr ||
            tail->next->value.prior < elm->value.prior)) ||
           (tail->value.prior > elm->value.prior &&
           ((tail->next != nullptr &&
           tail->next->value.prior < elm->value.prior)||
           (tail->next == nullptr)))) {
          elm->next = tail->next;
          tail->next = elm;
          return;
        }
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
