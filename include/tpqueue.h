// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cstdint>

template<typename T>
class TPQueue {
private:
    struct PAT {
        T data;
        PAT *next;
    };
    TPQueue::PAT *create(const T &);
    PAT *head;
    PAT *tail;
public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T &);
    T pop();

    void rmTail();

};

template<typename T>
typename TPQueue<T>::PAT *TPQueue<T>::create(const T &data) {
    PAT *pPat = new PAT;
    pPat->data = data;
    pPat->next = nullptr;
    return pPat;
}
template<typename T>
void TPQueue<T>::push(const T &data) {
    if (head == nullptr) {
        tail = create(data);
        head = tail;
    } else if (head == tail) {
        if (tail->data.prior < data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else {
            PAT *tempo = head;
            head = create(data);
            head->next = tempo;
        }
    } else {
        PAT *temp = head;
        if (data.prior > tail->data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else if (data.prior < head->data.prior) {
            PAT *t = head;
            head = create(data);
            head->next = t;
        } else {
            while (data.prior > temp->next->data.prior) {
                temp = temp->next;
            }
            PAT *tem = temp->next;
            temp->next = create(data);
            temp->next->next = tem;
        }
    }
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
    PAT *temp = head;
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
