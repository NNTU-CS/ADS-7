// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
    // реализация шаблона очереди с приоритетом на связанном списке
private:
    struct el {
        T element;
        el* nextPointer = nullptr;
    };
    el* head;
    void insertElementAfter(el* elemOfList, T elem) {
        el* insertingEl = new el;
        insertingEl->element = elem;
        insertingEl->nextPointer = elemOfList->nextPointer;
        elemOfList->nextPointer = insertingEl;
    }
    void insertHead(T elem) {
        el* insertingEl = new el;
        insertingEl->element = elem;
        insertingEl->nextPointer = head;
        head = insertingEl;
    }
    void removeHead() {
        head = head->nextPointer;
    }

public:
    TPQueue() { }
    void push(T element) {
        if (head == nullptr) {
            insertHead(element);
        }
        else {
            el* currentEl;
            currentEl = head;
            if (currentEl->element.prior < element.prior) {
                insertHead(element);
            }
            else {
                if (currentEl->nextPointer == nullptr) {
                    insertElementAfter(currentEl, element);
                    return;
                }
                while (currentEl->nextPointer != nullptr) {
                    if (currentEl->nextPointer->element.prior < element.prior) {
                        insertElementAfter(currentEl, element);
                        break;
                    }
                    currentEl = currentEl->nextPointer;
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
