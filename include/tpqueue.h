// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
template <typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
    };
    Item* head;
    Item* tail;
    Item* create(const T& data) {
        Item* item = new Item;
        item->data = data;
        item->next = nullptr;
        return item;
    }

  public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void addTail(const T& data) {
        if (tail && head) {
            tail->next = create(data);
            tail = tail->next;
        }
        else {
            head = create(data);
            tail = head;
        }
    }
    void addHead(const T& data) {
        if (tail && head) {
            Item* temp = create(data);
            temp->next = head;
            head = temp;
        }
        else {
            head = create(data);
            tail = head;
        }
    }
    void push(const T& item) {
        int pr = item.prior;
        if (head == nullptr || head->data.prior < pr)
            addHead(item);
        else if (tail->data.prior > pr)
            addTail(item);
        else {
            Item* elem = head;
            while (elem->next && elem->next->data.prior >= pr) {
                elem = elem->next;
            }
            Item* temp = elem->next;
            elem->next = create(item);
            elem->next->next = temp;
        }
    }
    T pop() {
        if (head == nullptr)
          throw std::string("is empty");
        Item* temp = head;
        head = head->next;
        T elem = temp->data;
        delete temp;
        return elem;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
