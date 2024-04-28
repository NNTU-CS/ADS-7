// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iterator>
#include <stdexcept>
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

    void push(const T& data, int prior) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prior = prior;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            if (prior > head->prior) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                while (current->next && prior <= current->next->prior) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                if (!newNode->next) {
                    tail = newNode;
                }
            }
        }
    }

    T pop() {
        if (!head) {
           throw std::out_of_range (" ");
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

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
