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
        if (tail && head) {
            tail->next = create(data);
            tail = tail->next;
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
