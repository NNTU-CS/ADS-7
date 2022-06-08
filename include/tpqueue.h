// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next;
        Item* prev;
    };
    TPQueue::Item* create(const T& value) {
        Item* item = new Item;
        item->value = value;
        item->next = nullptr;
        item->prev = nullptr;
        return item;
    }
    Item* head;
    Item* tail;

 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    void push(const T& value) {
        Item* comp = head;
        Item* item = create(value);
        while (comp && comp->value.prior >= value.prior) {
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
            Item* comp = head->next;
            if (comp) {
                comp->prev = nullptr;
            }
            T value = head->value;
            delete head;
            head = comp;
            if (!head) {
                tail = nullptr;
            }
            return value;
        } else {
            throw std::string("Empty");
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
