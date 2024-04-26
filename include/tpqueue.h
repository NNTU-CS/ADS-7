// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
    struct ITEM {
        T data;
        ITEM* next;
    };

 private:
    //TPQueue::ITEM* create(const T&);
    ITEM* head;
    ITEM* tail;
    ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        return item;
    }

 public:
    TPQueue() {
        head = nullptr;
        tail = nullptr;
    }
    void push(const T& data) {
    if (head && tail) {
        if (data.prior > head->data.prior) {
            ITEM* temp = create(data);
            temp->nnext = head;
            head = temp;
        } else if (tail->data.prior >= data.prior) {
            ITEM* temp = create(data);
            tail->nnext = temp;
            tail = temp;
        } else {
            ITEM* temp = create(data);
            ITEM* cur = head;
            while (cur->nnext->data.prior >= data.prior) {
                cur = cur->nnext;
            }
            temp->nnext = cur->nnext;
            cur->nnext = temp;
        }
    } else {
        head = create(data);
        tail = head;
    }
}
    T pop() {
        if (head) {
            ITEM* temp = head->next;
            T data = head->data;
            delete head;
            head = temp;
            return data;
        } else {
            throw std::string("empty");
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
