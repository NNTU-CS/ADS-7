// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
  struct QuList {
    T it;
    QuList* next;
  };
  QuList* a;
  QuList* b;

 public:
  TPQueue() : a(nullptr), b(nullptr) {}
  void push(const T& f) {
    QuList* newQu = new QuList{ f, nullptr };

    if (!a || a->it.prior < f.prior) {
      newQu->next = a;
      a = newQu;
    } else {
      QuList* c = a;
      while (c->next!=nullptr && c->next->it.prior >= f.prior) {
        c = c->next;
      }
      newQu->next = c->next;
      c->next = newQu;
    }
    if (!b)
      b = a;
  }
  const T pop() {
    //
    if (!a)
      throw "Queue empty";
    QuList* newQu = a;
    T x = newQu->it;
    a = a->next;
    delete newQu;
    return x;
  }
  bool empty() {
    return !a;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
