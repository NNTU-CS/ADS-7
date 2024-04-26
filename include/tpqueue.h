// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class tpqueue {
private:
    struct node {
        T data;
        int priority;
        node* next;
    };
    node* head;
    node* tail;

public:
    tpqueue() : head(nullptr), tail(nullptr) {}
    ~tpqueue() {
        while (!isEmpty()) {
            remove();
        }
    }
    void insert(const T& item, int priority) {
        node* newNode = new node;
        newNode->data = item;
        newNode->priority = priority;
        newNode->next = nullptr;
        if (isEmpty()) {
            head = tail = newNode;
        } else if (priority >= head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            node* current = head;
            while (current->next && priority < current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    T remove() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T item = head->data;
        node* temp = head;
        head = head->next;
        delete temp;
        if (isEmpty()) {
            tail = nullptr;
        }
        return item;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
