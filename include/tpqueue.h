// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
#include <iostream>

template<typename T>
class TPQueue {
    struct ITEM {
        T data;
        ITEM* next;
    };

private:
    ITEM* head;
    ITEM* tail;
    ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->next = nullptr;
        item->data = data;
        return item;
    }

public:
    TPQeue() {
        head = nullptr;
        tail = nullptr;
    }
void push(const T& data) {
    if (head && tail) {
        if (data.priority > head->data.priority) {
            ITEM* temp = create(data);
            temp->next = head;
            head = temp;
        } else if (tail->data.priority >= data.priority) {
            ITEM* temp = create(data);
            tail->next = temp;
            tail = temp;
        } else {
            ITEM* temp = create(data);
            ITEM* current = head;
            while (current->next->data.priority >= data.priority) {
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
            throw std::string("queue is empty");
        }
    }
};

struct SYM {
    char ch;
    int priority;
};

#endif  // INCLUDE_TPQUEUE_H_
