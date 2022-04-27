// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template <typename T>
class TPQueue {
 private:
      struct Item {
      T value;
      Item* next;
      };
  Item* head = nullptr;
TPQueue::Item* create(const T& value);
 public:
       TPQueue();
       explicit TPQueue(const T& value);
       void push(const T& value);
       T pop();
};

template <typename T>
        typename TPQueue <T>::Item* TPQueue<T>::create(const T& value) {
                Item* item = new Item;
                item->value = value;
                item->next = nullptr;
                return item;
        }

template <typename T>
        TPQueue <T>::TPQueue() {
                head = nullptr;
        }

        template <typename T>
        TPQueue <T>::TPQueue(const T& value) {
                 head = create(value);
        }

template <typename T>
        void TPQueue <T>::push(const T& value) {
              Item* temp = create(value);
              Item* current = nullptr;
                if (head == nullptr) {
                      head = temp;
                } else {
                       Item* first = head;
                         while (first != nullptr) {
                           if (first->value.prior > value.prior) {
                                  temp->value = first->value;
                                  temp->next = temp;
                           } else if (first->value.prior < value.prior) {
                                        temp->value = first->value;
                                        temp->next = first->next;
                                        first->value = value;
                                        first->next = temp;
                                       return;
                                  }
                                current = first;
                                first = first->next;
                       }
                 current->next = temp;
               }
       }

template <typename T>
T TPQueue <T>::pop() {
Item* current = nullptr;
T temp;
current = head;
    if (current != nullptr) {
        temp = current->value;
        head = current->next;
        return temp;
    }  else {
        throw std::string("Empty!");
       }
    }
struct SYM {
        char ch;
        int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
