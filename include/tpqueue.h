// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

    TPQueue() : head(nullptr) {}
      public:
    void push(const T& item) {
        Node* newNode = new Node;
        newNode->data = item;

        if (!head || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && item.prior <= current->next->data.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T pop() {
        if (!head) {
            std::cerr << "Queue is empty!" << std::endl;
            return T();
        }

        T item = head->data;
        Node* temp = head;
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
