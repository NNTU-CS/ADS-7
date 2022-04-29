// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
 private:
struct ITEM {
T data;
ITEM* next;
ITEM* prev;
};
ITEM* head;
ITEM* tail;
TPQueue::ITEM* create(const T& data) {
ITEM* item = new ITEM;
item->data = data;
item->next = nullptr;
item->prev = nullptr;
return item;
}

 public:
TPQueue() : head(nullptr), tail(nullptr) {}
~TPQueue() {
while (head)
    pop();
}
void push(const T& data) {
ITEM* temp = head;
ITEM* item = create(data);
while (temp && temp->data.prior >= data.prior)
    temp = temp->next;
if (!temp && head) {
    tail->next = item;
    tail->next->prev = tail;
    tail = item;
} else if (!temp && !head) {
    head = tail = item;
} else if (!temp->prev) {
    temp->prev = item;
    item->next = temp;
    head = item;
} else {
    temp->prev->next = item;
    item->prev = temp->prev;
    item->next = temp;
    temp->prev = item;
}
}

T pop() {
if (head) {
    ITEM* temp = head->next;
    if (temp)
        temp->prev = nullptr;
    T data = head->data;
    delete head;
    head = temp;
    return data;
} else {
    throw std::string(" Empty ! ");
}
}
};

struct SYM {
char ch;
int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
