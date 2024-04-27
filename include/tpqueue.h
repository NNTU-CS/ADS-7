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
    myItem *head;
    myItem *tail;
 public:
    TPQueue():head(nullptr), tail(nullptr) {}

    ~TPQueue();

    void push(const T&);

    T pop();
};

template<typename T>
TPQueue<T>::~TPQueue() {
    while (head)
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
    myItem *temp = head->next;
    T data = head->data;
    delete head;
    head = temp;
    return data;
}

template<typename T>
void TPQueue<T>::push(const T &data) {
    if (head == nullptr) {
        head = create(data);
        tail = head;
    } else if (head == tail) {
        if (data.prior > tail->data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else {
            myItem *item1 = head;
            head->next = item1;
            head = create(data);
        }
    } else {
        myItem *temp = head;
        if (data.prior >= tail->data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else if (data.prior < tail->data.prior) {
            myItem *item2 = head;
            head->next = item2;
            head = create(data);
        } else {
            while (temp->next && data.prior > temp->next->data.prior)
                temp = temp->next;
            myItem *ins = create(data);
            ins->next = temp->next;
            temp->next = ins;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
