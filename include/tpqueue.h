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
TPQueue::ITEM* create(const T& data) {
ITEM* item = new ITEM;
item->data = data;
item->next = nullptr;
item->prev = nullptr;
return item;
}
ITEM* head;
ITEM* tail;

 public:
T pop() {
if (head) {
ITEM* a = head->next;
if (a)
a->prev = nullptr;
T data = head->data;
delete head;
head = a;
return data;
} else {
throw std::string("Empty");
}
}
void push(const T& data) {
ITEM* a = head;
ITEM* item = create(data);
while (a && a->data.prior >= data.prior)
a = a->next;
if (!a && head) {
tail->next = item;
tail->next->prev = tail;
tail = item;
} else if (!a && !head) {
head = tail = item;
} else if (!a->prev) {
a->prev = item;
item->next = a;
head = item;
} else {
a->prev->next = item;
item->prev = a->prev;
item->next = a;
a->prev = item;
}
}
};

struct SYM {
char ch;
int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
