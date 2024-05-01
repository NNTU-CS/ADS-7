// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
   struct Item {
     T item;
     Item* next;
   };
   Item* start;
   Item* end;

 public:
   TPQueue(): start(nullptr), end(nullptr) {}
   void push(const T& value) {
   Item* temp = new Item;
   temp->item = value;
   temp->next = nullptr;
   if (start == nullptr) {
     start = temp;
     end = temp;
     return;
   }
   if (start->item.prior < value.prior) {
     temp->next = start;
     start = temp;
     return;
   }
     Item* i = start;
     while (i->next != nullptr && i->next->item.prior >= value.prior)
       i = i->next;
       temp->next = i->next;
       i->next = temp;
       if (temp->next == nullptr)
         end = temp;
       }
       const T pop() {
       Item* temp = start;
       T result = temp->item;
       start = start->next;
       delete temp;
       return result;
       }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
