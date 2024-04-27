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
  struct Node {
    T data;
    Node* next;
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}

  void push(const T& data) {
    Node* newNode = new Node{data, nullptr};
    if (!head || head->data.prior < data.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next && current->next->data.prior >= data.prior) {
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
    T data = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return data;
  }

  bool isEmpty() const { return head == nullptr; }

  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};

#endif  // INCLUDE_TPQUEUE_H_
