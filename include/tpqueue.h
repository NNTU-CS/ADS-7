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
    ITEM* start = nullptr;

 public:
    void push(const T& value);
    T pop();
};

template<typename T>
void TPQueue<T>::push(const T& value) {
    ITEM* first = start;
    if (first == nullptr) {
        first = new ITEM;
        start = first;
        first->data = value;
        first->next = nullptr;
    } else {
        ITEM* temp = new ITEM;
        temp->data = value;
        if (start->data.prior < temp->data.prior) {
            temp->next = first;
            start = temp;
            return;
        }
        while (first != nullptr) {
            if ((first->data.prior) >= (temp->data.prior) &&
                ((first->next) == nullptr ||
                    (((first->data.prior) < (temp->data.prior))
                        || ((first->next) != nullptr &&
                            first->next->data.prior < (temp->data.prior))))) {
                temp->next = first->next;
                first->next = temp;
                return;
            }
            first = first->next;
        }
    }
}

template<typename T>
T TPQueue<T>::pop() {
    ITEM* first = nullptr;
    first = start;
    if (first != nullptr) {
        T out = first->data;
        start = first->next;
        return out;
    } else {
        throw "Empty!";
    }
}

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
