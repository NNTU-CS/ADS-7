// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
    Node<T>* head;
public:
    TPQueue() : head(nullptr) {}
    void push(const T& item, int priority) {
        Node<T>* newNode = new Node<T>(item, priority);
        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next && priority <= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    T pop() {
        if (!head) {
            exit(1);
        }
        T item = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return item;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
