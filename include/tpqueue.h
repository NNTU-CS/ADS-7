// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
 private:
    struct Nod {
        T Date;
        Nod* Next;
    };

    Nod* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head) {
            Nod* temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void push(const T& el) {
        Nod* newNod = new Nod{el, nullptr};

        if (!head || head->Date.prior < el.prior) {
            newNod->Next = head;
            head = newNod;
        } else {
            Nod* current = head;
            while (current->Next && current->Next->Date.prior >= el.prior) {
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

        Nod* temp = head;
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
