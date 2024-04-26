// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
    struct ITEM {
        T data;
        int priority;
        ITEM* next;
    };

private:
    ITEM* head;
    ITEM* tail;
    ITEM* create(const T& data, int priority) {
        ITEM* newItem = new item;
        newItem->next = nullptr;
        newItem->data = data;
        newItem->priority = priority;
        return newItem;
    }

public:
    tpqeue() {
    head = null;
    tail = null;
    }
    void push(const T& data) {
        if (head && tail) {
            if (priority > head->priority) {
                ITEM* temp = create(data);
                temp->next = head;
                head = temp;
        } else if (tail->priority >= priority) {
                ITEM* temp = create(data);
                tail->next = temp;
                tail = temp;
            } else {
            ITEM* temp = create(data);
            ITEM* current = head;
            while (current->next->priority >= priority) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
        } else {
            head = create(data);
            tail = head;
        }
    }
    T pop() {
        if (head) {
            ITEM* temp = head->next;
            T data = head->data;
            delete head;
            head = temp;
            return data;
        } else {
            throw std::out_of_range("queue is empty");
        }
    }
};

struct Sym {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
