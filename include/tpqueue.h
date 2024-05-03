// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Item {
        T data;
        Item* dal;
    };
    Item* start;
    Item* end;
    int cnt = 0;

public:
    TPQueue() : start(nullptr), end(nullptr) {}
    void push(const T& value) {
        int p = value.prior;
        Item* temp = new Item;
        temp->data = value;
        temp->dal = nullptr;
        if (start == nullptr) {
            start = temp;
            end = temp;
            cnt++;
            return;
        }
        if (start->data.prior < p) {
            temp->dal = start;
            start = temp;
            cnt++;
            return;
        }
        Item* tail = start;
        for (int i = cnt - 1; i > 0; i--)
            if (tail->dal != nullptr && tail->dal->data.prior >= p)
                tail = tail->dal;
        temp->dal = tail->dal;
        tail->dal = temp;
        if (temp->dal == nullptr)
            end = temp;
    }
    const T pop() {
        Item* temp = start;
        T result = temp->data;
        start = start->dal;
        delete temp;
        return result;
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
