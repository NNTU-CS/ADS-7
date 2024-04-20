// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private :
    struct ITEM {
        T data;
        int prior;
        ITEM *next;
    };

    ITEM *first;
    ITEM *last;

 public :
    TPQueue() : first(nullptr), last(nullptr) {
    }

    ~TPQueue();

    void push(const T &);

    T pop();
};

template<typename T>
TPQueue<T>::~TPQueue() {
    while (first)
        pop();
}

template<typename T>
void TPQueue<T>::push(const T &item) {
    ITEM *temp = new ITEM;
    temp->data = item;
    temp->prior = item.prior;
    temp->next = nullptr;

    if (last != nullptr) {
        ITEM *cur = last;
        ITEM *prev = nullptr;
        while (cur != nullptr && item.prior > cur->prior) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == nullptr) {
            temp->next = first;
            first = temp;
        } else {
            prev->next = temp;
            temp->next = cur;
        }
    } else {
        first = temp;
    }

    last = temp;
}

template<typename T>
T TPQueue<T>::pop() {
    if (first == nullptr)
        throw std::out_of_range("Queue is empty");

    T data = first->data;

    ITEM *temp = first;
    first = first->next;
    delete temp;

    if (first == nullptr)
        last = nullptr;

    return data;
}

#endif  // INCLUDE_TPQUEUE_H_
