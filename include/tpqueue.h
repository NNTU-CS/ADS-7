// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
  SYM* prev;
  SYM* next;
};

template<typename T = SYM>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    SYM* st;
    SYM* end;
    int zero;

 public:
    TPQueue() : zero(0), st(nullptr), end(nullptr) {}
    void push(SYM temp) {
        if (!zero) {
            st = new SYM;
            st->ch = temp.ch;
            st->prior = temp.prior;
            st->next = st->prev = nullptr;
            end = st;
            zero++;
            return;
        } else {
            SYM* pre = end;
            if (temp.prior <= pre->prior) {
                SYM* q = new SYM;
                q->ch = temp.ch;
                q->prior = temp.prior;
                q->prev = q->next = nullptr;
                end->next = q;
                end->next->prev = end;
                end = end->next;
                zero++;
                return;
            } else if (temp.prior > st->prior) {
                SYM* q = new SYM;
                q->ch = temp.ch;
                q->prior = temp.prior;
                q->prev = q->next = nullptr;
                q->next = st;
                st->prev = q;
                st = q;
                zero++;
                return;
            } else {
                SYM* t = st;
                while (t->next && temp.prior <= t->prior)
                    t = t->next;
                SYM* q = new SYM;
                q->ch = temp.ch;
                q->prior = temp.prior;
                q->prev = q->next = nullptr;
                q->next = t;
                q->prev = t->prev;
                t->prev = q;
                q->prev->next = q;
                zero++;
            }
        }
    }
    SYM pop() {
        if (!zero) {
            SYM temp{ '0', -2 };
            return temp;
        } else {
            SYM u;
            u.ch = st->ch;
            u.prior = st->prior;
            st = st->next;
            zero--;
            return u;
        }
    }
};



#endif  // INCLUDE_TPQUEUE_H_
