// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Slist {
        Slist *next;
        T curr;
    };
    Slist *prev;
    Slist *end;

 public:
    TPQueue() : prev(nullptr), end(nullptr) {}

    void push(const T &item) {
        Slist *templ = new Slist;
        templ->curr = item;
        templ->next = nullptr;
        if (prev == nullptr) {
            prev = templ;
            end = templ;
            return;
        }
        if (prev->curr.prior < item.prior) {
            templ->next = prev;
            prev = templ;
        }
        Slist *h = prev;
        while (h->next != nullptr && h->next->curr.prior >= item.prior)
            h = h->next;
        templ->next = h->next;
        h->next = templ;
        if (templ->next == nullptr)
            end = templ;
    }

    const T pop() {
        Slist *templ = prev;
        T result = templ->curr;
        prev = prev->next;
        delete templ;
        return result;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
