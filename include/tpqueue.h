// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue{
 private:
struct ITEM {
    T ww;
    ITEM* nt;
};
ITEM* hd;
ITEM* tl;

 public:
    TPQueue() :hd(nullptr), tl(nullptr) {}
T pop() {
    ITEM* tm = hd;
    hd = hd->nt;
    return (tm->ww);
}
void push(T symb) {
    ITEM* tl = hd;
    if (tl == nullptr) {
        tl = new ITEM;
        hd = tl;
        tl->ww = symb;
        tl->nt = nullptr;
    } else {
        ITEM* elm = new ITEM;
        elm->ww = symb;
        if (hd->ww.prior < elm->ww.prior) {
            elm->nt = tl;
            hd = elm;
        }
        while (tl != nullptr) {
        if ((tl->ww.prior == elm->ww.prior &&
           (tl->nt == nullptr ||
            tl->nt->ww.prior < elm->ww.prior)) ||
           (tl->ww.prior > elm->ww.prior &&
           ((tl->nt != nullptr &&
           tl->nt->ww.prior < elm->ww.prior)||
           (tl->nt == nullptr)))) {
          elm->nt = tl->nt;
          tl->nt = elm;
          return;
        }
        tl = tl->nt;
      }
    }
}
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
