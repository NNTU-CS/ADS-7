#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
    SYM* prev;
    SYM* nt;
};

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
};
 private:
    SYM* head;
    SYM* tail;
    int cnt;

struct SYM {
  char ch;
  int prior;
 public:
    TPQueue() : cnt(0), head(nullptr), tail(nullptr) {}
    void push(SYM item) {
        if (!cnt) {
            head = new SYM;
            head->ch = item.ch;
            head->prior = item.prior;
            head->nt = head->prev = nullptr;
            tail = head;
            cnt++;
            return;
        } else {
           SYM* temp = tail;
           if (item.prior <= temp->prior) {
               SYM* p = new SYM;
               p->ch = item.ch;
               p->prior = item.prior;
               p->prev = p->nt = nullptr;
               tail->nt = p;
               tail->nt->prev = tail;
               tail = tail->nt;
               cnt++;
               return;
           } else if (item.prior > head->prior) {
               SYM* a = new SYM;
               a->ch = item.ch;
               a->prior = item.prior;
               a->prev = p->nt = nullptr;
               a->nt = head;
               head->prev = a;
               head = a;
               cnt++;
               return;
           } else {
               SYM* h = head;
               while (h->nt && item.prior <= h->prior)
                   h = h->nt;
               SYM* a = new SYM;
               a->ch = item.ch;
               a->prior = item.prior;
               a->prev = a->nt = nullptr;
               a->nt = h;
               a->prev = h->prev;
               h->prev = a;
               a->prev->nt = a;
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
            head = head->nt;
            cnt--;
            return temp;
        }
    }
};

#endif  // INCLUDE_TPQUEUE_H_
