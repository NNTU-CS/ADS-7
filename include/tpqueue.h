// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T = SYM>
class TPQueue {
 private:
    SYM* head;
    SYM* last;
    int count;

 public:
    TPQueue() : count(0), head(nullptr), last(nullptr) {}
    void push(SYM a) {
        if (!count) {
            head = new SYM;
            head->ch = a.ch;
            head->prior = a.prior;
            head->next = head->prev = nullptr;
            last = head;
            count++;
            return;
        } else {
           SYM* temp = last;
           if (a.prior <= temp->prior) {
               SYM* b = new SYM;
               b->ch = a.ch;
               b->prior = a.prior;
               b->prev = b->next = nullptr;
               last->next = b;
               last->next->prev = last;
               last = last->next;
               count++;
               return;
           } else if (a.prior > head->prior) {
               SYM* b = new SYM;
               b->ch = a.ch;
               b->prior = a.prior;
               b->prev = b->next = nullptr;
               b->next = head;
               head->prev = b;
               head = b;
               count++;
               return;
           } else {
               SYM* h = head;
               while (h->next && a.prior <= h->prior)
                   h = h->next;
               SYM* b = new SYM;
               b->ch = a.ch;
               b->prior = a.prior;
               b->prev = b->next = nullptr;
               b->next = h;
               b->prev = h->prev;
               h->prev = b;
               b->prev->next = b;
               count++;
           }
        }
    }
    SYM pop() {
        if (!count) {
            SYM a{ '0', -2 };
            return a;
        } else {
            SYM temp;
            temp.ch = head->ch;
            temp.prior = head->prior;
            head = head->next;
            count--;
            return temp;

        }
    }
};

struct SYM {
  char ch;
  int prior;
  SYM* prev;
  SYM* next;
};

#endif  // INCLUDE_TPQUEUE_H_
