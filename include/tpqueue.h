// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T>
class TPQueue{
 private:
struct List {
  T value;
  List* next;
};
List* begin;

 public:
  TPQueue() :begin(nullptr) {}
void push(T data) {
  List* start = begin;
  if (start == nullptr) {
    start = new List;
    begin = start;
    start->value = data;
    start->next = nullptr;
  } else {
      List* dop = new List;
      dop->value = data;
      if (begin->value.prior < dop->value.prior) {
        dop->next = start;
        begin = dop;
        return;
      }
      while (start != nullptr) {
        if ((start->value.prior == dop->value.prior &&
           (start->next == nullptr ||
            start->next->value.prior < dop->value.prior)) ||
           (start->value.prior > dop->value.prior
           && ((start->next != nullptr
           && start->next->value.prior < dop->value.prior)
           || (start->next == nullptr)))) {
          dop->next = start->next;
          start->next = dop;
          return;
        }
        start = start->next;
      }
    }
}
T pop() {
  List* temp = begin;
  begin = begin->next;
  return (temp->value);
}
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
