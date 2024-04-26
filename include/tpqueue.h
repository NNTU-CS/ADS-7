// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
#include <stdexcept>

template<typename T>
class TPQueue {
    struct Item {
        T data;
        int priority;
        Item* next;
    };

private:
    Item* head;
    Item* tail;

    Item* create(const T& data, int priority) {
        Item* item = new Item;
        item->next = nullptr;
        item->data = data;
        item->priority = priority;
        return item;
    }

public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    void push(const T& data, int priority) {
        Item* temp = create(data, priority);
      
        if (!head) {
            head = temp;
            tail = temp;
        }
        else if (priority > head->priority) {
            temp->next = head;
            head = temp;
        }
        else if (priority <= tail->priority) {
            tail->next = temp;
            tail = temp;
        }
        else {
            Item* current = head;
            while (current->next->priority >= priority) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    T pop() {
        if (head) {
            Item* temp = head->next;
            T data = head->data;
            delete head;
            head = temp;
            return data;
        }
        else {
            throw std::out_of_range("Queue is empty");
        }
    }
};

struct Sym {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
