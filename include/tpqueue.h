// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
  struct Node {
    T item;
    Node* next = nullptr;
    Node* prev = nullptr;
  };
  Node* create(const T& item) {
    Node* node = new Node;
    node->item = item;
    return node;
  }
  bool IsEmpty() {
    return head == nullptr;
  }
  Node* head;
  Node* tail;
  Node* current;

 public:
  TPQueue() {
    head = tail = current = nullptr;
  }
  ~TPQueue() {
    if (IsEmpty()) {
      return;
    } else if (head->next) {
      current = head->next;
      while (current != tail) {
        delete current->prev;
        current = current->next;
      }
      delete tail;
    } else {
      delete head;
    }
  }
  void push(T item) {
    if (IsEmpty()) {
      head = tail = create(item);
    } else {
      Node* temp = create(item);
      current = head;
      if (item.prior <= head->item.prior && item.prior > tail->item.prior) {
        while (item.prior <= current->item.prior) {
          current = current->next;
        }
        current = current->prev;
        temp->prev = current;
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
      } else if (item.prior > head->item.prior) {
        temp->next = head;
        head->prev = temp;
        head = temp;
      } else {
        tail->next = temp;
        tail->next->prev = tail;
        tail = tail->next;
      }
    }
  }
  T pop() {
    if (head && tail) {
      Node* temp = head->next;
      if (head->next != nullptr) {
        temp->prev = nullptr;
      }
      T data = head->item;
      delete head;
      head = temp;
      if (head == nullptr)
        tail = nullptr;
      return data;
    } else {
      T fake{'0', -10};
      return fake;
    }
  }
};

struct Symbol {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
