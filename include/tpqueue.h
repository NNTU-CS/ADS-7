// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue{
 private:
struct ITEM {
    T v;
    ITEM* next;
};
ITEM* h;
ITEM* tail;

 public:
    TPQueue() :h(nullptr), tail(nullptr) {}
T pop() {
    ITEM* t = h;
    h = h->next;
    return (t->v);
}
void push(T symb) {
    ITEM* tail = h;
    if (tail == nullptr) {
        tail = new ITEM;
        h = tail;
        tail->v = symb;
        tail->next = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->v = symb;
        if (h->v.prior < elm->v.prior) {
            elm->next = tail;
            h = elm;
        }
        while (tail != nullptr) {
        if ((tail->v.prior == elm->v.prior &&
           (tail->next == nullptr ||
            tail->next->v.prior < elm->v.prior)) ||
           (tail->v.prior > elm->v.prior &&
           ((tail->next != nullptr &&
           tail->next->v.prior < elm->v.prior)||
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
