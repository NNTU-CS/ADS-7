// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};
template<typename T>
class TPQueue {
public:
    TPQueue() : head(nullptr), tail(nullptr), size(0) {}

    ~TPQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& data) {
        if (head == nullptr || data.prior > head->data.prior) {
            head = new Node(data, head, nullptr);
            if (tail == nullptr) {
                tail = head;
            } else {
                head->next->prev = head;
            }
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data.prior >= data.prior) {
                current = current->next;
            }
            if (current->next == nullptr) {
                current->next = new Node(data, nullptr, current);
                tail = current->next;
            } else {
                Node* newNode = new Node(data, current->next, current);
                current->next->prev = newNode;
                current->next = newNode;
            }
        }
        size++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Очередь пуста");
        }
        T value = head->data;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        size--;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
