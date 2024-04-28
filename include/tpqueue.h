// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    void insertSorted(Node* newNode);
    Node* removeFirst();

public:
    TPQueue() : head(nullptr), tail(nullptr), size(0) {}

    ~TPQueue();

    bool isEmpty() const { return size == 0; }

    void enqueue(const T& value);

    T dequeue();
};


template<typename T>
TPQueue<T>::~TPQueue() {
    while (!isEmpty()) {
        removeFirst();
    }
}


template<typename T>
void TPQueue<T>::insertSorted(Node* newNode) {
    if (head == nullptr || newNode->data >= head->data) {
        newNode->next = head;
        if (tail == nullptr) {
            tail = newNode;
        } else {
            tail->prev = newNode;
        }
        head = newNode;
    } else {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && newNode->data < current->data) {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        newNode->next = current;
        if (current == tail) {
            tail = newNode;
        } else {
            newNode->prev = current->prev;
            current->prev = newNode;
        }
    }
    size++;
}


template<typename T>
typename TPQueue<T>::Node* TPQueue<T>::removeFirst() {
    if (head == nullptr) {
        return nullptr;
    }
    Node* first = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    size--;
    return first;
}


template<typename T>
void TPQueue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    insertSorted(newNode);
}


template<typename T>
T TPQueue<T>::dequeue() {
    Node* first = removeFirst();
    if (first == nullptr) {
        return T();
    }
    T retValue = first->data;
    delete first;
    return retValue;

};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
