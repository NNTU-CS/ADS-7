// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
struct SYM {
  char ch;
  int prior;
};
struct Node {
  SYM data;
  Node* next;
};
template<typename T>
class TPQueue {
private: 
  Node* head;
  Node* tail;

public: 
  TPQueue() : head(nullptr), tail(nullptr) {}
  ~TPQueue() { clear(); }
  void push(const T& item) {
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;
    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    } else {
      Node* current = head;
      Node* prev = nullptr;
      while (current != nullptr && current->data.prior >= item.prior) {
        prev = current;
        current = current->next;
      }
      if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
      } else {
        prev->next = newNode;
        newNode->next = current;
      }
    }
  }
  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Queue is empty");
    }
    T front = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
      tail = nullptr;
    }
    return front;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
  void clear() {
    while (!isEmpty()) {
      pop();
    }
  }
};
int main() {
  TPQueue<SYM> queue;
  SYM item1 = {'A', 3};
  queue.push(item1);
  SYM item2 = {'B', 2};
  queue.push(item2);
  SYM item3 = {'C', 1};
  queue.push(item3);
  SYM front = queue.pop();
  std::cout << "Front: " << front.ch << ",
    Priority: " << front.prior << std::endl;
  front = queue.pop();
  std::cout << "Front: " << front.ch << ",
    Priority: " << front.prior << std::endl;
  front = queue.pop();
  std::cout << "Front: " << front.ch << ",
    Priority: " << front.prior << std::endl;
  return 0;
}
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
