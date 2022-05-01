// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T data;
        ITEM* next;
    };
    ITEM* start_s;

 public:
    TPQueue():start_s(nullptr) {}
    void push(T value) {
        ITEM* start = start_s;
        if (start == nullptr) {
            start = new ITEM;
            start_s = start;
            start->data = value;
            start->next = nullptr;
        } else {
            ITEM* temp = new ITEM;
            temp->data = value;
            if (start_s->data.prior < temp->data.prior) {
                temp->next = start;
                start_s = temp;
                return;
            }
            while (start != nullptr) {
                if ((start->data.prior) >= (temp->data.prior) &&
                    ((start->next) == nullptr ||
                     (((start->data.prior) < (temp->data.prior)) ||
                      ((start->next) != nullptr &&
                       start->next->data.prior < (temp->data.prior))))) {
                    temp->next = start->next;
                    start->next = temp;
                    return;
                }
                start = start->next;
            }
        }
    }
    T pop() {
        ITEM* start = nullptr;
        start = start_s;
        if (start != nullptr) {
            T rem = start->data;
            start_s = start->next;
            return rem;
        } else {
            throw "Empty!";
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
