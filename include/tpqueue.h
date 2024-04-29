// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
    };
    Item* head;
    Item* create(const T& value) {
        Item* temp = new Item;
        temp->data.ch = value.ch;
        temp->data.prior = value.prior;
        return temp;
    }

 public:
    TPQueue() :head(nullptr) {}
    void push(const T& value) {
        Item* temp = create(value);
        Item* temp_head = head;
        head = temp_head;
        if (!head) {
            head = temp;
            head->next = nullptr;
            return;
        }
        while (temp_head) {
            if (temp->data.prior > temp_head->data.prior && temp_head == head) {
                temp->next = temp_head;
                head = temp;
                break;
            } else if (temp->data.prior == temp_head->data.prior) {
                temp->next = temp_head->next;
                temp_head->next = temp;
                break;
            } else if (temp->data.prior > temp_head->next->data.prior) {
                temp->next = temp_head->next;
                temp_head->next = temp;
                break;
            }
            temp_head = temp_head->next;
            if (!temp_head->next) {
                temp_head->next = temp;
                break;
            }
        }
    }
    T pop() {
        Item* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
