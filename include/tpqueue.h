// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
template<typename T>
class TPQueue {
 private:
    struct Node {
        T Date;
        Node* Next;
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void push(const T& elem) {
        Node* newNode = new Node{elem, nullptr};

        if (!head || head->Date.prior < elem.prior) {
            newNode->Next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->Next && current->Next->Date.prior >= elem.prior) {
                current = current->Next;
            }
            newNode->Next = current->Next;
            current->Next = newNode;
        }
    }

    T pop() {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = head;
        T Date = temp->Date;
        head = head->Next;
        delete temp;
        return Date;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
