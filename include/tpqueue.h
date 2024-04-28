// Copyright 2022 NNTU-CS
#include <string>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

struct sys {
    SYM sym;
    sys* next;
};

template<typename T = SYM>
class TPQueue {
 private:
    sys* ptr;

 public:
    TPQueue() : ptr(nullptr) {}

    void push(T newsym) {
        sys* list = new sys;
        list->sym = newsym;
        list->next = nullptr;

        if (ptr == nullptr || \
            newsym.prior > ptr->sym.prior) {
            list->next = ptr;
            ptr = list;
        } else {
            sys* tmp = ptr;
            while (tmp->next != nullptr && \
                tmp->next->sym.prior > newsym.prior) {
                tmp = tmp->next;
            }
            list->next = tmp->next;
            tmp->next = list;
        }
    }

    T pop() {
        T reset = ptr->sym;
        sys* tempor = ptr;
        ptr = ptr->next;
        delete tempor;
        return reset;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
