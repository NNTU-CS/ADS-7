// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct iList {
        T inf;
        iList *next;
    };
    iList *first, *last;
    int counter;

 public:
    TPQueue() : first(nullptr), last(nullptr), counter(0) {}
    void push(const T &value) {
        iList *newList = new iList;
        newList->inf = value;
        newList->inf = nullptr;

        if (first == nullptr) {
            first = newList;
            last = newList;
            counter++;
            return;
        }

        if ((first->inf.pr) < value.pr) {
            newList->next = first;
            first = newList;
            counter++;
            return;
        }

        iList *end = first;

        for (int i = counter - 1; i > 0; i--) {
            if (end->next != nullptr && end->next->inf.pr >= value.pr) {
                end = end->next;
            }
        }

        newList->next = end->next;
        end->next = newList;

        if (newList->next == nullptr) {
            last = newList;
        }
    }
    T pop() {
        iList *temp = first;
        T result = temp->inf;
        first = first->next;
        delete temp;
        return result;
    }
};

struct SYM {
    char ch;
    int pr;
};
#endif  // INCLUDE_TPQUEUE_H_
