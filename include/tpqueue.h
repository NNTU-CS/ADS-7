// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T value;
        ITEM* next;
        ITEM* prev;
    };
    ITEM* head, * tail;
    TPQueue::ITEM* create(const T& value) {
        ITEM* item = new ITEM;
        item->value = value;
        item->next = item->prev = nullptr;
        return item;
    }

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }
    void push(const T& value) {
        ITEM* itemPlace = head;
        ITEM* item = create(value);
        while (itemPlace && itemPlace->value.prior >= value.prior)
            itemPlace = itemPlace->next;
        if (!itemPlace && head) {
            tail->next = item;
            item->prev = tail;
            tail = item;
            return;
        } else if (!itemPlace && !head) {
            head = tail = item;
        } else if (!itemPlace->prev) {
            head->prev = item;
            item->next = head;
            head = item;
        } else {
            itemPlace->prev->next = item;
            item->prev = itemPlace->prev;
            item->next = itemPlace;
            itemPlace->prev = item;
        }
    }
    T pop() {
        ITEM* temp = head->next;
        if (temp)
            temp->prev = nullptr;
        T value = head->value;
        delete head;
        head = temp;
        if (!head)
            tail = nullptr;
        return value;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
