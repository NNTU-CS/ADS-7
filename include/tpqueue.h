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
void push(T symbol) {
    ITEM* tl = hh;
    if (tl == nullptr) {
        tl = new ITEM;
        hh = tl;
        tl->vv = symbol;
        tl->next = nullptr;
    } else {
        ITEM* elem = new ITEM;
        elem->vv = symbol;
        if (hh->vv.prior < elem->vv.prior) {
            elem->next = tl;
            hh = elem;
        }
        while (tl != nullptr) {
        if ((tl->vv.prior == elem->vv.prior &&
           (tl->next == nullptr ||
            tl->next->vv.prior < elem->vv.prior)) ||
           (tl->vv.prior > elem->vv.prior &&
           ((tl->next != nullptr &&
           tl->next->vv.prior < elem->vv.prior)||
           (tl->next == nullptr)))) {
          elem->next = tl->next;
          tl->next = elem;
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
