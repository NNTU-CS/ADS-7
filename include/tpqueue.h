// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T value;
        ITEM* next, * prev;
    };
    ITEM* head, * tail, * curr;
    TPQueue::ITEM* newIT(const T& value) {
        ITEM* item = new ITEM;
        item->next = nullptr;
        item->prev = nullptr;
        item->value = value;
        return item;
    }

 public:
    TPQueue() {
        tail = head = curr = nullptr;
    }
     T pop() {
         if (head != nullptr) {
             T value = head->value;
             head = head->next;
             return value;
         } else {
             throw std::string("Queue is empty");
         }
     }
     void push(const T&value) {
         ITEM* temp = head;
         ITEM* item = newIT(value);
         if (head == nullptr) {
             head = item;
             return;
         }
         ITEM* prev = nullptr;
         while (temp && temp->value.prior >= value.prior) {
             prev = temp;
             temp = temp->next;
         }
             if (temp == nullptr) {
                 prev->next = item;
             } else {
                 if (prev == nullptr) {
                     item->next = head;
                     head = item;
                 } else {
                     item->next = temp;
                     prev->next = item;
                 }
             }
         }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
