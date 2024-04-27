// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>

class TPQueue {
private:
    struct node {
        SYM data;
        node* next;
    };
    node* head;
public:
    TPQueue() : head(nullptr) {}

    void push(SYM new_sym) {
        node* new_node = new node{ new_sym, nullptr };
        if (head == nullptr || new_sym.prior > head->data.prior) {
            new_node->next = head;
            head = new_node;
        } else {
            node* tmp = head;
            while (tmp->next != nullptr && new_sym.prior <= tmp->next->data.prior) {
                tmp = tmp->next;
            }
            new_node->next = tmp->next;
            tmp->next = new_node;
          }
    }
    SYM pop() {
        if (head == nullptr) {
            return SYM{ '0', 0 };
        }
        SYM last = head->data;
        node* tmp = head;
        head = head->data;
        delete t;
        return last;
    } 
}
#endif  // INCLUDE_TPQUEUE_H_
