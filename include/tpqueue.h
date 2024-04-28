// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T>
class TPQueue {
 private:
    struct Structure {
        T data;
        Structure* next;
    };
    Structure* forward;
    Structure* back;

 public:
    TPQueue() : forward(nullptr), back(nullptr) {}
    void push(const T& data) {
        Structure* newStruct = new Structure{data, nullptr};
        if (!forward || forward->data.prior < data.prior) {
            newStruct->next = forward;
            forward = newStruct;
        } else {
            Structure* now = forward;
            while (now->next &&  data.prior <= now->next->data.prior) {
                now = now->next;
            }
            newStruct->next = now->next;
            now->next = newStruct;
        }
        if (!back) {
            back = forward;
        }
    }
    T pop() {
        if (!forward) {
            throw std::out_of_range("Empty slots");
        }
        T data = forward->data;
        Structure* temp = forward;
        forward = forward->next;
        delete temp;
        if (!forward) {
            back = nullptr;
        }
        return data;
    }
    bool is_empty() const {
        return !forward;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
