// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

struct Node {
    int data;
    int priority;
    Node* next;
};

class TPQueue {
 private:
    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    void enqueue(int data, int priority) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->priority = priority;

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr&&current->next->priority>=priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int dequeue() {
        if (head == nullptr) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        return data;
    }

    void printQueue() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << current->priority << std::endl;
            current = current->next;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
