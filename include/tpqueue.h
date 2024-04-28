// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct elementOfList {
    T element;
    elementOfList* nextPointer = nullptr;
  };
  elementOfList* head;
  void insertElementAfter(elementOfList* elemOfList, T elem) {
    elementOfList* insertingElementOfTheList = new elementOfList;
    insertingElementOfTheList->element = elem;
    insertingElementOfTheList->nextPointer = elemOfList->nextPointer;
    elemOfList->nextPointer = insertingElementOfTheList;
  }
  void insertHead(T elem) {
  elementOfList* insertingElementOfTheList = new elementOfList;
  insertingElementOfTheList->element = elem;
  insertingElementOfTheList->nextPointer = head;
  head = insertingElementOfTheList;
  }
  void removeHead() {
  head = head->nextPointer;
  }

 public:
  TPQueue() { }
  void push(T element) {
    if (head == nullptr) {
      insertHead(element);
    } else {
      elementOfList* currentElementOfList;
      currentElementOfList = head;
      if (currentElementOfList->element.prior < element.prior) {
      insertHead(element);
      } else {
        if (currentElementOfList->nextPointer == nullptr) {
          insertElementAfter(currentElementOfList, element);
          return;
        }
      while (currentElementOfList->nextPointer != nullptr) {
        if (currentElementOfList->nextPointer->element.prior < element.prior) {
          insertElementAfter(currentElementOfList, element);
          break;
        }
          currentElementOfList = currentElementOfList->nextPointer;
        }
      }
    }
  }
  T pop() {
    T res = head->element;
    removeHead();
    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
