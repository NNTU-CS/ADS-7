// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cstddef>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
    struct Node {
        T date;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* end;

 public:
    TPQueue() {
        head = NULL;
        end = NULL;
    }
    void push(T elm) {
        Node* value = new Node;
        value->date = elm;
        value->next = NULL;
        value->prev = NULL;
        if (head == NULL) {
            head = end = value;
        } else if (elm.prior <= head->date.prior) {
            value->next = head;
            head->prev = value;
            head = value;
        } else if (elm.prior > end->date.prior) {
            end->next = value;
            value->prev = end;
            end = value;
        } else {
            Node* insert = end;
            for (Node* i = head; i->next != NULL; i = i->next) {
                if (elm.prior < i->next->date.prior) {
                    insert = i;
                    break;
                }
            }
            value->next = insert->next;
            insert->next->prev = value;
            value->prev = insert->next;
            insert->next = value;
        }
    }
    T pop() {
        Node* temp = end;
        end = end->prev;
        return temp->date;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
