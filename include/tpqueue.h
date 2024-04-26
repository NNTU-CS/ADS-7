// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  struct SYM {
    char ch;
    int prior;
  };
  struct node {
    SYM data;
    node* next;
  };
  
  private:
    node* head;
    node* tail;

  public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    void push(const T& item) {
      node* newNode = new node;
      newNode->data = item;
      newNode->next = nullptr;
      
      if (head == nullptr) {
        head = newNode;
        tail = newNode;
      } else if (newNode->data.prior < head->data.prior) {
        newNode->next = head;
        head = newNode;
      } else if (newNode->data.prior >= tail->data.prior) {
        tail->next = newNode;
        tail = newNode;
      } else {
        node* current = head->next;
        node* prev = head;
        
        while (current != nullptr) {
          if (newNode->data.prior >= current->data.prior) {
            prev->next = newNode;
            newNode->next = current;
            break;
          }
          prev = current;
          current = current->next;
        }
      }
    }

    T pop() {
      if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
      }
      
      node* temp = head;
      T item = temp->data;
      
      if (head == tail) {
        head = nullptr;
        tail = nullptr;
      } else {
        head = head->next;
      }
      
      delete temp;
      
      return item;
    }

    bool empty() const {
      return head == nullptr;
    }

    ~TPQueue() {
      while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
      }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
