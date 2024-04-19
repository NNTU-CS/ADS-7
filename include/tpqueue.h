// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
#include <iostream>
struct SYM {
    char ch;
    int prior;
};

class Node {
 public:
    Node* prev, * next;
    SYM data;
    Node *insert(SYM data) {
        Node *_next = this->next;
        this->next = new Node(data);
        this->next->next = _next;
        this->next->prev = this;
        if(_next) {
            _next->prev = this->next;
        }
        return this->next;
    }
    Node *erase() {
        Node *_next = this->next;
        Node *_pred = this->prev;
        delete(this);
        if(_next) {
            _next->prev = _pred;
        }
        if(_pred) {
            _pred->next = _next;
            return _pred;
        }
        return _next;
    }
    Node* erase() {
        Node* _next = this->next;
        Node* _pred = this->prev;
        delete(this);
        if (_next) {
            _next->prev = _pred;
        }
        if (_pred) {
            _pred->next = _next;
            return _pred;
        }
        return _next;
    }
};

template <typename T>

class TPQueue {
 public:
    Node* head, * tail;
    int size;

 public:
    TPQueue() {
        this->head = this->tail = NULL;
        size = 0;
    }
    SYM pop() {
        if (!size) throw "error";
        SYM tmp = head->data;
        head = head->erase();
        size--;
        return tmp;
    }
    void push(SYM a) {
        if (!size) {
            head = tail = new Node(a);
            size++;
            return;
        }
        Node* cur = tail;
        while (cur && cur->data.prior < a.prior) {
            cur = cur->next;
        }
        if (cur) {
            if (cur == tail) {
                tail = cur->insert(a);
            } else {
                cur->insert(a);
            }
        } else {
            head = head->insert(a);
        }
        size++;
    }
    ~TPQueue() {
        while (size) {
            std::cout << pop().ch;
        }
    }
};

#endif  // INCLUDE_TPQUEUE_H_
