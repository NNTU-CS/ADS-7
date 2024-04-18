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
        T item;
        Slist *next;
    };
    Slist *prev;
    Slist *end;

 public:
    TPQueue() : prev(nullptr), end(nullptr) {}

    void push(const T &val) {
        Slist *temp = create(val);
        if (prev == nullptr) {
            prev = temp;
            end = temp;
        } else {
            if (val.prior > prev->item.prior) {
                temp->next = prev;
                prev = temp;
            } else {
                Slist *g = prev;
                while (g->next != nullptr && g->next->item.prior >= val.prior)
                    g = g->next;
                temp->next = g->next;
                g->next = temp;
                if (temp->next == nullptr)
                    end = temp;
            }
        }
    }

    const T pop() {
        Slist *temp = prev;
        T result = temp->item;
        prev = prev->next;
        delete temp;
        return result;
    }

    bool isEmpty() const {
        return prev == nullptr;
    }

 private:
    Slist *create(const T &val) {
        Slist *temp = new Slist;
        temp->item = val;
        temp->next = nullptr;
        return temp;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
