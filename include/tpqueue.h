// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T>
class TPQueue {
 private:
    Node<T>* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& data) {
        if (head == nullptr || head->data.prior < data.prior) {
            head = new Node<T>(data, head);
        } else {
            Node<T>* current = head;
            while (current->next != nullptr && 
                   current->next->data.prior >= data.prior) {
                current = current->next;
            }
            current->next = new Node<T>(data, current->next);
        }
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Очередь пуста");
        }
        Node<T>* temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        return data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
