// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
    }* head;

 public:
    TPQueue() : head(nullptr) {}

    void push(T sim) {
        Node* newSim = new Node{ sim, nullptr };
        if (!head || sim.prior > head->data.prior) {
            newSim->next = head;
            head = newSim;
        } else {
            Node* last = head;
            while (last->next && sim.prior <= last->next->data.prior) {
                last = last->next;
            }
            newSim->next = last->next;
            last->next = newSim;
        }
    }

    T pop() {
        if (!head) {
            std::cout << "Queue is empty!" << std::endl;
            return T();
        }
        T data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
