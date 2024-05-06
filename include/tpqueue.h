// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head;
    T pop_value;
    TPQueue::Item* create(const T&);

 public:
    TPQueue(): head(nullptr) {}
    ~TPQueue();
    void push(const T&);
    const T& pop();
};

template<typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& value) {
    Item* temp = new Item;
    temp->value = value;
    temp->next = nullptr;
    return temp;
}

template<typename T>
void TPQueue<T>::push(const T& value) {
    Item* tmp = new Item;
    tmp->value = value;
    tmp->next = nullptr;
    if (head == nullptr) {
        head = tmp;
    } else {
        Item* p = head;
        Item* q = nullptr;
        while (p != nullptr && p->value.prior >= value.prior) {
            q = p;
            p = p->next;
        }
        if (q == nullptr) {
            tmp->next = head;
            head = tmp;
        } else {
            tmp->next = q->next;
            q->next = tmp;
        }
    }
}

template<typename T>
const T& TPQueue<T>::pop() {
    if (head == nullptr) {
        throw std::string("Queue is empty");
    } else {
        Item* next_head = head->next;
        pop_value = head->value;
        delete head;
        head = next_head;
        return pop_value;
    }
}

template<typename T>
TPQueue<T>::~TPQueue() {
    while (head) {
        Item* next_head = head->next;
        delete head;
        head = next_head;
    }
}

struct SYM {
   char ch;
   int prior;

#endif  // INCLUDE_TPQUEUE_H_
