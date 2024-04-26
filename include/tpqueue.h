// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
#include <stdexcept>

template<typename T>
class tpqueue {
    struct item {
        T data;
        int priority;
        item* next;
    };

private:
    item* head;
    item* tail;

    item* create(const T& data, int priority) {
        item* newItem = new item;
        newItem->next = nullptr;
        newItem->data = data;
        newItem->priority = priority;
        return newItem;
    }

public:
    tpqueue() : head(nullptr), tail(nullptr) {}

    void push(const T& data, int priority) {
        item* temp = create(data, priority);
        if (!head) {
            head = temp;
            tail = temp;
        } else if (priority > head->priority) {
            temp->next = head;
            head = temp;
        } else if (priority <= tail->priority) {
            tail->next = temp;
            tail = temp;
        } else {
            item* current = head;
            while (current->next->priority >= priority) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    T pop() {
        if (head) {
            item* temp = head->next;
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
