// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
    };
    Item* head;
    Item* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void push(const T& data) {
      Item* new_mode = new Item{data, nullptr};
      if (!head || head->data.prior < data.prior) {
        new_mode->next = head;
        head = new_mode;
      } else {
        Item* current = head;
        while (current->next &&  current->next->data.prior >= data.prior) {
          current = current->next;
        }
        new_mode->next = current->next;
        current->next = new_mode;
      }
      if (!tail) {
        tail = head;
      }
    }
    T pop() {
      if (!head) {
        throw std::out_of_range("Empty!");
      }
      T data = head->data;
      Item* temp = head;
      head = head->next;
      delete temp;
      if (!head) {
        tail = nullptr;
      }
      return data;
    }
    bool is_empty() {
      return !head;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
