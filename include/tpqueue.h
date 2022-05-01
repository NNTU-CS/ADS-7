// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
// реализация шаблона очереди с приоритетом на связанном списке
 private:
    struct ITEM {
        T value;
        ITEM* prev, * next;
    };
    ITEM* head, * tail, * actual;
    TPQueue::ITEM* create(const T& value) {
        ITEM* item = new ITEM;
        item->value = value;
        item->prev = nullptr;
        item->next = nullptr;
        return item;
    }

 public:
    TPQueue() {
        head = tail = actual = nullptr;
    }
    ~TPQueue() {
        while (head)
            pop();
    }
    T getNext() {
        if (tail && head ) {
            if (!actual)
                actual = head;
            else if (actual->next)
                actual = actual->next;
            else
                throw std::string("Beyond border");
            return actual->value;
        } else {
            throw std::string("Beyond border");
        }
    }
    T pop() {
        if (tail && head ) {
            ITEM* temp = head->next;


#endif  // INCLUDE_TPQUEUE_H_
