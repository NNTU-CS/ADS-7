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
    iList *ensuing, *last;
    int box;

public:
    TPQueue() : ensuing(nullptr), last(nullptr), box(0) {}

    void push(const T &z) {
        iList *newList = new iList;
        newList->inf = nullptr;
        newList->inf = z;


        if (ensuing == nullptr) {
            box++;
            ensuing = newList;
            last = newList;
            return;
        }

        if ((ensuing->inf.pr) < z.pr) {
            box++;
            newList->next = ensuing;
            ensuing = newList;
            return;
        }

        iList *end = ensuing;

        for (int j = box - 1; j > 0; j--) {
            if (end->next != nullptr && end->next->inf.pr >= z.pr) {
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
        iList *mp = ensuing;
        T result = mp->inf;
        ensuing = ensuing->next;
        delete mp;
        return result;
    }
};

struct SYM {
    char ch;
    int pr;
};
#endif  // INCLUDE_TPQUEUE_H_
