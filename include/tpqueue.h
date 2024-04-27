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

    SOR *hd;
    SOR *tl;

public:
    TPQueue() : hd(nullptr), tl(nullptr) {}

    ~TPQueue();

    void push(const T &);

    T pop();

    void rmTail();
};

template<typename T>
typename TPQueue<T>::SOR *TPQueue<T>::create(const T &data) {
    SOR *pVal = new SOR;
    pVal->data = data;
    pVal->next = nullptr;
    return pVal;
}

template<typename T>
void TPQueue<T>::push(const T &data) {
    SOR *newNode = create(data);

    if (hd == nullptr) {
        tl = newNode;
        hd = tl;
    } else if (hd == tl) {
        if (tl->data.prior < data.prior) {
            tl->next = newNode;
            tl = tl->next;
        } else {
            newNode->next = hd;
            hd = newNode;
        }
    } else {
        if (data.prior > tl->data.prior) {
            tl->next = newNode;
            tl = tl->next;
        } else if (data.prior < hd->data.prior) {
            newNode->next = hd;
            hd = newNode;
        } else {
            SOR *temp = hd;
            while (temp->next && data.prior > temp->next->data.prior) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

template<typename T>
T TPQueue<T>::pop() {
    T temp = tl->data;
    rmTail();
    return temp;
}

template<typename T>
TPQueue<T>::~TPQueue() {
    while (tl) {
        pop();
    }
}

template<typename T>
void TPQueue<T>::rmTail() {
    SOR *temp = hd;
    if (hd == tl) {
        delete tl;
        hd = tl = nullptr;
    } else {
        while (temp->next != tl) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tl;
        tl = temp;
    }
}

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
