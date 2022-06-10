// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T data;
        ITEM* next;
        ITEM* prev;
    };
    TPQueue::ITEM* create(const T& value) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        item->prev = nullptr;
        return item;
    }
    ITEM* head;
    ITEM* tail;

 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    void push(const T& value) {
        ITEM* comp = head;
        ITEM* item = create(data);
        while (comp && comp->data.prior >= data.prior) {
            comp = comp->next;
        }
        if (head && !comp) {
            tail->next = item;
            item->prev = tail;
            tail = item;
        } else if (!comp && !head) {
            head = tail = item;
        } else if (!comp->prev) {
            head->prev = item;
            item->next = head;
            head = item;
        } else {
            comp->prev->next = item;
            item->prev = comp->prev;
            item->next = comp;
            comp->prev = item;
        }
  }
T pop() {
        if (head && tail) {
            ITEM* comp = head->next;
            if (comp) {
                comp->prev = nullptr;
            }
            T data = head->data;
            delete head;
            head = comp;
            if (!head) {
                tail = nullptr;
            }
            return data;
        } else {
            throw "Empty";
        }
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
