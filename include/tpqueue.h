// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class TPQueue {
    struct ITEM {
        T data;
        ITEM* next;
    };

 public:
    TPQueue(): head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head) {
            pop();
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
            throw(std::string("Empty"));
        }
    }
    void push(const T& data) {
        if (head && tail) {
            if (data.prior > head->data.prior) {
                ITEM* temp = create(data);
                temp->next = head;
                head = temp;
            } else if (tail->data.prior >= data.prior) {
                ITEM* temp = create(data);
                tail->next = temp;
                tail = temp;
            } else {
                ITEM* temp = create(data);
                ITEM* cur = head;
                while (cur->next->data.prior >= data.prior) {
                    cur = cur->next;
                }
                temp->next = cur->next;
                cur->next = temp;
            }
        } else {
            head = create(data);
            tail = head;
        }
    }

 private:
    ITEM* head;
    ITEM* tail;
    ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        return item;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
