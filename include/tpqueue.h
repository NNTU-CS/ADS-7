// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue{
 private:
struct ITEM {
    T vv;
    ITEM* next;
};
ITEM* hh;
ITEM* tl;

 public:
    TPQueue() :hh(nullptr), tl(nullptr) {}
T pop() {
    ITEM* tt = hh;
    hh = hh->next;
    return (tt->vv);
}
void push(T symb) {
    ITEM* tl = hh;
    if (tl == nullptr) {
        tl = new ITEM;
        hh = tl;
        tl->vv = symb;
        tl->next = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->vv = symb;
        if (hh->vv.prior < elm->vv.prior) {
            elm->next = tl;
            hh = elm;
        }
        while (tl != nullptr) {
        if ((tl->vv.prior == elm->vv.prior &&
           (tl->next == nullptr ||
            tl->next->vv.prior < elm->vv.prior)) ||
           (tl->vv.prior > elm->vv.prior &&
           ((tl->next != nullptr &&
           tl->next->vv.prior < elm->vv.prior)||
           (tl->next == nullptr)))) {
          elm->next = tl->next;
          tl->next = elm;
          return;
        }
        tl = tl->next;
      }
    }
}
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
