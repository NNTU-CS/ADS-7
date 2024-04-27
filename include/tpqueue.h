// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
    SYM* pred;
    SYM* sled;
};

template<typename T = SYM>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    SYM* beg;
    SYM* end;
    int counter;

 public:
    TPQueue() : counter(0), beg(nullptr), end(nullptr) {}
    void push(SYM j) {
        if (!counter) {
            beg = new SYM;
            beg->ch = j.ch;
            beg->prior = j.prior;
            beg->sled = beg->pred = nullptr;
            end = beg;
            counter++;
            return;
        } else {
            SYM* tmp = end;
            if (j.prior <= tmp->prior) {
                SYM* e = new SYM;
                e->ch = j.ch;
                e->prior = j.prior;
                e->pred = e->sled = nullptr;
                end->sled = e;
                end->sled->pred = end;
                end = end->sled;
                counter++;
                return;
            } else if (j.prior > beg->prior) {
                SYM* e = new SYM;
                e->ch = j.ch;
                e->prior = j.prior;
                e->pred = e->sled = nullptr;
                e->sled = beg;
                beg->pred = e;
                beg = e;
                counter++;
                return;
            } else {
                SYM* f = beg;
                while (f->sled && j.prior <= f->prior)
                    f = f->sled;
                SYM* e = new SYM;
                e->ch = j.ch;
                e->prior = j.prior;
                e->pred = e->sled = nullptr;
                e->sled = f;
                e->pred = f->pred;
                f->pred = e;
                e->pred->sled = e;
                counter++;
            }
        }
    }

    SYM pop() {
        if (!counter) {
            SYM a{ '0', -2 };
            return a;
        } else {
            SYM tmp;
            tmp.ch = beg->ch;
            tmp.prior = beg->prior;
            beg = beg->sled;
            counter--;
            return tmp;
        }
    }
};



#endif  // INCLUDE_TPQUEUE_H_
