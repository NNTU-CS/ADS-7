// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iterator>
#include <stdexcept>

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        int prior;
    };

    Node* head;
    Node* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    void push(const SYM& item) {
    Node* newItem = new Node;
    newItem->data = item;
    newItem->prior = item.prior;
    newItem->next = nullptr;

    if (!head) {
        head = newItem;
        tail = newItem;
    } else {
        if (item.prior > head->prior) {
            newItem->next = head;
            head = newItem;
        } else {
            Node* current = head;
            while (current->next && item.prior <= current->next->prior) {
                current = current->next;
            }
            newItem->next = current->next;
            current->next = newItem;
            if (!newItem->next) {
                tail = newItem;
            }
        }
    }
}

    T pop() {
        if (!head) {
          throw std::out_of_range(" ");
        }

        T data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return !head;
    }

    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


#endif  // INCLUDE_TPQUEUE_H_
