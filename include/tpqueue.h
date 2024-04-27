// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T>
class TPQueue {
 private:
    int first;
    int last;
    struct ITEM {
        T data;
        ITEM* next;
    };
    ITEM* head;
    ITEM* tail;
 public:
    TPQueue() :first(0), last(0), head(nullptr), tail(nullptr) {}
    void push(T x) {
        if (last - first >= size)
            throw std::string("Full!");
        ITEM* item = head;
        ITEM* prev = nullptr;
        while (item) {
            T s = item->data;
            if (x.prior > s.prior) {
                break;
            }
            prev = item;
            item = item->next;
        }
        if (!item) {
            addTail(x);
        } else {
            if (prev) {
                insertAfter(prev, x);
            } else {
                addHead(x);
            }
        }
        last++;
    }
    T pop() {
        first++;
        return rmHead();
    }
    int getSize() {
        return (last - first);
    }
 private:
    ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        return item;
    }
    void addTail(const T& data) {
        if (tail && head) {
            tail->next = create(data);
            tail = tail->next;
        } else {
            head = create(data);
            tail = head;
        }
    }
    void addHead(const T& data) {
        if (tail && head) {
            ITEM* temp = create(data);
            temp->next = head;
            head = temp;
        } else {
            head = create(data);
            tail = head;
        }
    }
    void insertAfter(ITEM* prev, const T& data) {
        ITEM* next = prev->next;
        ITEM* new_item = create(data);
        prev->next = new_item;
        new_item->next = next;
    }
    T rmHead() {
        if (head) {
            ITEM* temp = head->next;
            T data = head->data;
            delete head;
            head = temp;
            return data;
        }
        throw std::string("Empty queue");
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
