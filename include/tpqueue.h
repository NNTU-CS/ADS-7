// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cstdint>

template<typename T>
class TPQueue {
 private:
    struct VAL {
        T data;
        VAL *next;
    };

    TPQueue::VAL *create(const T &);

    VAL *head;
    VAL *tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue();

    void push(const T &);

    T pop();

    void rmTail();
};

template<typename T>
typename TPQueue<T>::VAL *TPQueue<T>::create(const T &data) {
    VAL *pVal = new VAL;
    pVal->data = data;
    pVal->next = nullptr;
    return pVal;
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
            VAL *temp1 = head;
            head = create(data);
            head->next = temp1;
        }
    } else {
        VAL *temp2 = head;
        if (data.prior > tail->data.prior) {
            tail->next = create(data);
            tail = tail->next;
        } else if (data.prior < head->data.prior) {
            VAL *t = head;
            head = create(data);
            head->next = t;
        } else {
            while (data.prior > temp2->next->data.prior) {
                temp2 = temp2->next;
            }
            VAL *tem = temp2->next;
            temp2->next = create(data);
            temp2->next->next = tem;
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
    VAL *temp = head;
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
