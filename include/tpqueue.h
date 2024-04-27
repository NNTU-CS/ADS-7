// Copyright 2022 NNTU-CS
#include <string>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

struct Qlist {
    SYM sym;
    Qlist* next;
};

template<typename T = SYM>
class TPQueue {
 private:
    Qlist* base;

 public:
    TPQueue() : base(nullptr) {}

    void push(T newsym) {
        Qlist* Newlist = new Qlist;
        Newlist->sym = newsym;
        Newlist->next = nullptr;

        if (base == nullptr || newsym.prior > base->sym.prior) {
            Newlist->next = base;
            base = Newlist;
        } else {
            Qlist* tmp = base;
            while (tmp->next != nullptr && tmp->next->sym.prior > newsym.prior) {
                tmp = tmp->next;
            }
            Newlist->next = tmp->next;
            tmp->next = Newlist;
        }
    }

    T pop() {
        T str_ret = base->sym;
        Qlist* tempor = base;
        base = base->next;
        delete tempor;
        return str_ret;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
