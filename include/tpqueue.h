// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T data;
        ITEM *next;
    };
    ITEM *start = nullptr;
 public:
    void push(const T& data);
    T pop();
};

template<typename T>
void TPQueue<T>::push(const T& data) {
    if (start == nullptr) {
        start = new ITEM();
        start->data = data;
        start->next = nullptr;
    } else {
        ITEM *startLocal = nullptr;
        ITEM *endLocal = nullptr;
        startLocal = start;
        while (startLocal != nullptr) {
            if (startLocal->data.prior < data.prior) {
                ITEM *temp = new ITEM();
                temp->data = startLocal->data;
                temp->next = startLocal->next;
                startLocal->data = data;
                startLocal->next = temp;
                return;
            }
            endLocal = startLocal;
            startLocal = startLocal->next;
        }
        ITEM *temp = new ITEM();
        temp->data = data;
        temp->next = nullptr;
        endLocal->next = temp;
    }
}

template<typename T>
T TPQueue<T>::pop() {
    ITEM *startLocal = nullptr;
    startLocal = start;
    if (startLocal != nullptr) {
        T temp = startLocal->data;
        start = startLocal->next;
        return temp;
    } else {
        throw std::string("List is empty!");
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
