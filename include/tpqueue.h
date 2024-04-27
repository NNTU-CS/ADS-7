// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cstdint>

template<typename T>
class TPQueue {
 private:
    struct SOR {
        T data;
        SOR *next;
    };

    TPQueue::SOR *create(const T &);

    SOR *head;
    SOR *tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue();

    void push(const T &);

    T pop();

    void rmTail();
};

template<typename T>
typename TPQueue<T>::SOR *TPQueue<T>::create(const T &data) {
    SOR *pSor = new SOR;
    pSor->data = data;
    pSor->next = nullptr;
    return pSor;
}

template<typename T>
void TPQueue<T>::push(const T &data) {
    if (head == nullptr) {
        tail = create(data);
        head = tail;
        return;
    }

    SOR *newNode = create(data);

    if (data.prior > tail->data.prior) {
        tail->next = newNode;
        tail = newNode;
        return;
    }

    if (data.prior < head->data.prior) {
        newNode->next = head;
        head = newNode;
        return;
    }

    SOR *temp = head;
    while (temp->next && data.prior > temp->next->data.prior) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

template<typename T>
T TPQueue<T>::pop() {
    T temp = tail->data;
    rmTail();
    return temp;
}

template<typename T>
TPQueue<T>::~TPQueue() {
    while (tail) {
        pop();
    }
}

template<typename T>
void TPQueue<T>::rmTail() {
    SOR *temp = head;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
}

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
