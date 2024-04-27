// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T>
class TPQueue {
 private:
    struct myItem {
        T data;
        myItem* next;
    };
    TPQueue::myItem *create(const T&);
    myItem *headItem;
    myItem *tailItem;
 public:

    TPQueue():headItem(nullptr), tailItem(nullptr) {}

    ~TPQueue();

    void push(const T&);

    T pop();

    void rmTail() {
        myItem *templ = headItem;
        if (headItem != tailItem) {
            while (templ->next != tailItem) {
                templ = templ->next;
            }
            templ->next = nullptr;
            delete tailItem;
            tailItem = templ;
        } else {
            delete tailItem;
            headItem = tailItem = nullptr;
        }
    }

};

template<typename T>
TPQueue<T>::~TPQueue() {
    while (headItem)
        pop();
}

template<typename T>
typename TPQueue<T>::myItem*TPQueue<T>::create(const T &data) {
    myItem *item = new myItem;
    item->data = data;
    item->next = nullptr;
    return item;
}

template<typename T>
T TPQueue<T>::pop() {
    T temp4 = tailItem->data;
    rmTail();
    return temp4;
}

template<typename T>
void TPQueue<T>::push(const T &data) {
    if (headItem == nullptr) {
        tailItem = create(data);
        headItem = tailItem;
    } else if (headItem == tailItem) {
        if (data.prior > tailItem->data.prior) {
            tailItem->next = create(data);
            tailItem = tailItem->next;
        } else {
            myItem *item1 = headItem;
            headItem = create(data);
            headItem->next = item1;
        }
    } else {
        myItem *temp = headItem;
        if (data.prior > tailItem->data.prior) {
            tailItem->next = create(data);
            tailItem = tailItem->next;
        } else if (data.prior < headItem->data.prior) {
            myItem *item3 = headItem;
            headItem = create(data);
            headItem->next = item3;
        } else {
            while (data.prior > temp->next->data.prior) {
                temp = temp->next;
            }
            myItem *ins = temp->next;
            temp->next = create(data);
            temp->next->next = ins;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
