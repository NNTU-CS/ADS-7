// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T = SYM>
class TPQueue {
 private:
    SYM* head;
    SYM* tail;
    int count;

 public:
    TPQueue() : count(0), head(nullptr), tail(nullptr) {}
    void push(SYM a) {
        if (!count) {
            head = new SYM;
            head->ch = a.ch;
            head->prior = a.prior;
            head->next = head->prev = nullptr;
            count++;
            return;
        } else {
           SYM* temp = tail;
           if (a.prior <= temp->prior) {
               SYM* p = new SYM;
               p->ch = a.ch;
               p->prior = a.prior;
               p->prev = p->next = nullptr;
               head->next = p;
               head->next->prev = head;
               head = head->next;
               count++;
               return;
           } else if (a.prior > head->prior) {
               SYM* p = new SYM;
               p->ch = a.ch;
               p->prior = a.prior;
               p->prev = p->next = nullptr;
               p->next = head;
               head->prev = p;
               head = p;
               count++;
               return;
           } else {
               SYM* h = head;
               while (h->next && a.prior <= h->prior)
                   h = h->next;
               SYM* p = new SYM;
               p->ch = a.ch;
               p->prior = a.prior;
               p->prev = p->next = nullptr;
               p->next = h;
               p->prev = h->prev;
               h->prev = p;
               p->prev->next = p;
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
  char ch;
  int prior;
  SYM* prev;
  SYM* next;
};

#endif  // INCLUDE_TPQUEUE_H_
