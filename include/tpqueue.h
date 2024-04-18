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
        T current;
    };
    Slist *prev;
    Slist *end;

    Slist *create(const T &item) {
        Slist *templ = new Slist;
        templ->current = item;
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
            if (item.prior > prev->current.prior) {
                templ->next = prev;
                prev = templ;
            } else {
                Slist *hoop = prev;
                while (item.prior <= hoop->next->current.prior && hoop->next != nullptr)
                    hoop = hoop->next;
                templ = hoop->next;
                hoop->next = templ;
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
