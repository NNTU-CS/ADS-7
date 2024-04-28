// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
  SYM* prev;
  SYM* next;
};

template<typename T>
class TPQueue {
 private:
  SYM* head;
  SYM* tail;
  int cnt;

 public:
  TPQueue() : cnt(0), head(nullptr), tail(nullptr) {}

  void push(SYM item) {
    if (!cnt) {
      head = new SYM;
      head->ch = item.ch;
      head->prior = item.prior;
      head->next = head->prev = nullptr;
      tail = head;
      cnt++;
      return;
    } else {
      SYM* temp = tail;
      if (item.prior <= temp->prior) {
        SYM* q = new SYM;
        q->ch = item.ch;
        q->prior = item.prior;
        q->prev = q->next = nullptr;
        tail->next = q;
        tail->next->prev = tail;
        tail = tail->next;
        cnt++;
        return;
      } else if (item.prior > head->prior) {
        SYM* q = new SYM;
        q->ch = item.ch;
        q->prior = item.prior;
        q->prev = q->next = nullptr;
        q->next = head;
        head->prev = q;
        head = q;
        cnt++;
        return;
      } else {
        SYM* h = head;
        while (h->next && item.prior <= h->prior)
          h = h->next;
        SYM* q = new SYM;
        q->ch = item.ch;
        q->prior = item.prior;
        q->prev = q->next = nullptr;
        q->next = h;
        q->prev = h->prev;
        h->prev = q;
        q->prev->next = q;
        cnt++;
      }
    }
  }

  SYM pop() {
    if (!cnt) {
      SYM a{ '0', -2 };
      return a;
    } else {
      SYM temp;
      temp.ch = head->ch;
      temp.prior = head->prior;
      head = head->next;
      cnt--;
      return temp;
    }
  }
};

#endif  // INCLUDE_TPQUEUE_H_
