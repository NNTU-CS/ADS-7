// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    int count;
    struct st {
        T data;
        st* next;
    };
    st* frst;
    st* last;
public:
    TPQueue() : frst(nullptr), last(nullptr), count(0) {}
    void push(const T& value) {
        st* nst = new st;
        nst->next = nullptr;
        nst->data = value;
        if (frst == nullptr) {
            frst = nst;
            last = nst;
            count++;
            return;
        }
        if ((frst->data.prior) < value.prior) {
            nst->next = frst;
            frst = nst;
            count++;
            return;
        }
        st* end = frst;
        for (int i = count - 1; i > 0; i--) {
            if (end->next != nullptr && end->next->data.prior >= value.prior) {
                end = end->next;
            }
        }
        nst->next = end->next;
        end->next = nst;
        if (nst->next == nullptr) {
            last = nst;
        }
    }
    T pop() {
        st* temp = frst;
        T result = temp->data;
        frst = frst->next;
        delete temp;
        return result;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
