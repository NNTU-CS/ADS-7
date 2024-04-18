// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
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

    Slist *create(const T &item) {
        Slist *templ = new Slist;
        templ->curr = item;
        templ->next = nullptr;
        return templ;
    }

 public:
    TPQueue() : prev(nullptr), end(nullptr) {}

    void push(const T &item) {
        Slist *templ = create(item);
        if (prev == nullptr) {
            end = templ;
            prev = templ;
        } else {
            if (item.prior > prev->curr.prior) {
                templ->next = prev;
                prev = templ;
            } else {
                Slist *h = prev;
                while (item.prior <= h->next->curr.prior && h->next != nullptr)
                    h = h->next;
                templ->next = h->next;
                h->next = templ;
                if (templ->next == nullptr)
                    end = templ;
            }
        }
    }

    const T pop() {
        if (isEmpty()) {
            std::cout << "empty!" << std::endl;
            exit(EXIT_FAILURE);
        }
        Slist *temp = prev;
        T result = temp->current;
        prev = prev->next;
        delete temp;
        return result;
    }

    bool isEmpty() const {
        return prev == nullptr;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
