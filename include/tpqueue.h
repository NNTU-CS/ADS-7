// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct iList {
        T data;
        iList *next;
    };
    iList *head, *tail;

    iList *create(T data) {
        auto *item = new iList;
        item->data = data;
        item->next = nullptr;
        return item;
    }

public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue() {
        while (head)
            pop();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T pop() {
        iList *temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }

    void push(const T &data) {
        if (tail && head) {
            iList *begin = head;
            iList *newItem = create(data);
            if (head == tail) {
                if (data.prior > head->data.prior) {
                    newItem->next = head;
                    head = newItem;
                } else {
                    head->next = newItem;
                    tail = newItem;
                }
            } else {
                iList *prev = nullptr;
                while (begin != tail && data.prior <= begin->data.prior) {
                    prev = begin;
                    begin = begin->next;
                }
                if (data.prior > begin->data.prior) {
                    newItem->next = begin;
                    if (prev) {
                        prev->next = newItem;
                    } else {
                        head = newItem;
                    }
                } else {
                    tail->next = newItem;
                    tail = newItem;
                }
            }
        } else {
            head = create(data);
            tail = head;
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
