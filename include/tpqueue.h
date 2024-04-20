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
void TPQueue<T>::push(const T& item) {
    // Создаем новый элемент очереди
    ITEM* temp = new ITEM;
    temp->data = item;
    temp->prior = item.prior;
    temp->next = nullptr;

    if (first == nullptr || item.prior > first->prior) {
        temp->next = first;
        first = temp;
    } else {
        ITEM* cur = first;
        while (cur->next != nullptr && cur->next->prior >= item.prior) {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }

    if (temp->next == nullptr) {
        last = temp;
    }
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

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
