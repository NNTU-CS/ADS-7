// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    SYM* head;
    SYM* tail;
    int counter;

 public:
    TPQueue() : counter(0), head(nullptr), tail(nullptr) {}
    void push(SYM item) {
        if (!counter) {
            head = new SYM;
            head->ch = item.ch;
            head->prior = item.prior;
            head->next = head->prev = nullptr;
            tail = head;
            counter++;
            return;
        } else {
           SYM* temp = tail;
           if (item.prior <= temp->prior) {
               SYM* p = new SYM;
               p->ch = item.ch;
               p->prior = item.prior;
               p->prev = p->next = nullptr;
               tail->next = p;
               tail->next->prev = tail;
               tail = tail->next;
               counter++;
               return;
           } else if (a.prior > head->prior) {
               SYM* p = new SYM;
               p->ch = item.ch;
               p->prior = item.prior;
               p->prev = p->next = nullptr;
               p->next = head;
               head->prev = p;
               head = p;
               counter++;
               return;
           } else {
               SYM* h = head;
               while (h->next && item.prior <= h->prior)
                   h = h->next;
               SYM* p = new SYM;
               p->ch = item.ch;
               p->prior = item.prior;
               p->prev = p->next = nullptr;
               p->next = h;
               p->prev = h->prev;
               h->prev = p;
               p->prev->next = p;
               counter++;
           }
        }
    }
    SYM pop() {
        if (!counter) {
            SYM a{ '0', -2 };
            return a;
        } else {
            SYM temp;
            temp.ch = head->ch;
            temp.prior = head->prior;
            head = head->next;
            counter--;
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
