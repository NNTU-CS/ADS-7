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
    myItem *temp1 = headItem->next;
    T data = headItem->data;
    delete headItem;
    headItem = temp1;
    return data;
}

template<typename T>
void TPQueue<T>::push(const T &data) {
    if (headItem == nullptr) {
        headItem = create(data);
        tailItem = headItem;
    } else if (headItem == tailItem) {
        if (tailItem->data.prior == data.prior) {
            tailItem->next = create(data);
            tailItem = tailItem->next;
        } else if (data.prior > headItem->data.prior) {
            myItem *item2 = headItem;
            headItem = create(data);
            headItem->next = item2;
        } else {
            myItem *item1 = headItem;
            headItem = create(data);
            headItem->next = item1;
        }
    } else {
        myItem *temp = headItem;
        if (data.prior < tailItem->data.prior) {
            tailItem->next = create(data);
            tailItem = tailItem->next;
        } else if (data.prior > headItem->data.prior) {
            headItem = create(data);
            headItem->next = temp;
        } else {
            while (data.prior < temp->next->data.prior)
                temp = temp->next;
            myItem *ins = temp->next;
            ins->next = create(data);
            temp->next->next = ins;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
