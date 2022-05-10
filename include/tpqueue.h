// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
  };
  ITEM* head;
  ITEM* tail;
  TPQueue::ITEM* create(const T& cif) {
      ITEM* item = new ITEM;
      item->data = cif;
      item->next = nullptr;
      return item;
  }

 public:
  TPQueue() :head(nullptr), tail(nullptr) {}
  T pop() {
      if (head) {
          ITEM* temp = head;
          head = head->next;
          return temp->data;
      }
      T t;
      t.prior = 0;
      t.ch = ' ';
      return t;
  }
  void push(T cif) {
      ITEM* t = nullptr;
      ITEM* item = create(cif);
      ITEM* temp = head;
      if (head && tail) {
        while (temp && (temp->data).prior >= cif.prior) {
            t = temp;
            temp = temp->next;
        }
        if (temp == head && ((head->data).prior == (item->data).prior)) {
            item->next = head->next;
            head->next = item;
        } else if (temp == head && ((item->data).prior) <= (head->data).prior) {
            item->next = head->next;
            head->next = item;
        } else if (temp == head && ((item->data).prior) > (head->data).prior) {
            item->next = head;
            head = item;
        } else if (!temp) {
            tail->next = item;
            tail = item;
        } else {
            t->next = item;
            item->next = temp;
        }
    } else {
        head = create(cif);
        tail = head;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
