// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue{
 private:
struct ITEM {
    T w;
    ITEM* n;
};
ITEM* hd;
ITEM* tl;

 public:
    TPQueue() :hd(nullptr), tl(nullptr) {}
T pop() {
    ITEM* tt = hd;
    hd = hd->n;
    return (tt->w);
}
void push(T symb) {
    ITEM* tl = hd;
    if (tl == nullptr) {
        tl = new ITEM;
        hd = tl;
        tl->w = symb;
        tl->n = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->w = symb;
        if (hd->w.prior < elm->w.prior) {
            elm->n = tl;
            hd = elm;
        }
        while (tl != nullptr) {
        if ((tl->w.prior == elm->w.prior &&
           (tl->n == nullptr ||
            tl->n->w.prior < elm->w.prior)) ||
           (tl->w.prior > elm->w.prior &&
           ((tl->n != nullptr &&
           tl->n->w.prior < elm->w.prior)||
           (tl->n == nullptr)))) {
          elm->n = tl->n;
          tl->n = elm;
          return;
        }
        tl = tl->n;
      }
    }
}
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
