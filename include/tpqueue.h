// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Element {
        T data;
        Element* next;
    };
    Element* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }

    void push(const T& data) {
        Element* newElement = new Element;
        newElement->data = data;
        newElement->next = nullptr;

        if (!head || data.prior > head->data.prior) {
            newElement->next = head;
            head = newElement;
        } else {
            Element* current = head;
            while (current->next && data.prior <= current->next->data.prior)
                current = current->next;
            newElement->next = current->next;
            current->next = newElement;
        }
    }
  T pop() {
        if (!head)
            throw "Queue empty";
        ELEMENT* exmplocheredi = head;
        head = head->next;
        T data = exmplocheredi->data;
        delete exmplocheredi;
        if (!head)
            ukazatel = nullptr;
        return data;
    }
  bool isEmpty() const {
        return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
