// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
  };
  ITEM* first_o;

 public:
  TPQueue():first_o(nullptr) {}

  void push(T value) {
    ITEM* first = first_o;
    if (first == nullptr) {
      first = new ITEM;
      first_o = first;
      first->data = value;
      first->next = nullptr;
    } else {
        ITEM* temp = new ITEM;
        temp->data = value;
        if (first_o->data.prior < temp->data.prior) {
          temp->next = first;
          first_o = temp;
          return;
        }
        while (first != nullptr) {
          //prov1 = first->data.prior;
          //prov2 = temp->data.prior;
          //prov3 = first->next; //соответствие
          if ((first->data.prior) >= (temp->data.prior) &&
        ((first->next) == nullptr ||
         (((first->data.prior) < (temp->data.prior))
          || ((first->next) != nullptr &&
              first->next->data.prior < (temp->data.prior))))) {
            temp->next = first->next;
            first->next = temp;
            return;
          }
          first = first->next;
        }
     }
  }
  T pop() {
    ITEM *first = nullptr;
    first = first_o;
    if (first != nullptr) {
        T extract = first->data;
        first_o = first->next;
        return extract;
    } else {
        throw "Empty!";
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
