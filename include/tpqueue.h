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
  Node* tail;
  int count = 0;

  public:
  TPQueue(): head(nullptr), tail(nullptr) {}

  void push(const T& val) {
    int pr = val.prior;
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    
    if (head == nullptr) {
      head = temp;
      tail = temp;
      count++;
      
      return;
    }
    
    if (head->data.prior < pr) {
      temp->next = head;
      head = temp;
      count++;
    }
    
    Node* end = head;
    for (int k = count-1; k > 0; k--)
      if (end->next != nullptr && end->next->data.prior >= pr)
        end = end->next;
    
    temp->next = end->next;
    end->next = temp;
    
    if (temp->next == nullptr)
      tail = temp->next;
  }

  const T pop() {
    Node* temp = head;
    T result = temp->data;
    head = head->next;
    delete temp;
    
    return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
