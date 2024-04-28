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

    void removeTail();
};

template<typename T>
typename TPQueue<T>::PAT *TPQueue<T>::create(const T &data) {
    PAT *pat = new PAT;
    pat->data = data;
    pat->next = nullptr;
    return pat;
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
            PAT *temp = head;
            head = create(data);
            head->next = temp;
        }
    } else {
        PAT *tempo = head;
        if (data.prior > tail->data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else if (data.prior < head->data.prior) {
            PAT *te = head;
            head = create(data);
            head->next = te;
        } else {
            while (data.prior > tempo->next->data.prior) {
                tempo = tempo->next;
            }
            PAT *tep = tempo->next;
            tempo->next = create(data);
            tempo->next->next = tep;
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    T tempo = tail->data;
    removeTail();
    return tempo;
}
template<typename T>
TPQueue<T>::~TPQueue() {
    while (tail) {
        pop();
    }
}
template<typename T>
void TPQueue<T>::removeTail() {
    PAT *tempo = head;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        while (tempo->next != tail) {
            tempo = tempo->next;
        }
        tempo->next = nullptr;
        delete tail;
        tail = tempo;
    }
}
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
