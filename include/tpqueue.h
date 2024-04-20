// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ELEMENT {
        T data;
        ELEMENT* next;
    };
    ELEMENT* head;
    ELEMENT* ukazatel;

 public:
    TPQueue() : head(nullptr), ukazatel(nullptr) {}
    ~TPQueue() {
        while (head)
            pop();
    }
    void push(const T& data) {
        ELEMENT* exmplocheredi = new ELEMENT;
        exmplocheredi->data = data;
        exmplocheredi->next = nullptr;
        if (!head) {
            head = exmplocheredi;
        } else {
            if (data.prior > head->data.prior) {
                exmplocheredi->next = head;
                head = exmplocheredi;
            } else {
                ELEMENT* current = head;
                while (current->next && data.prior <= current->next->data.prior)
                    current = current->next;
                exmplocheredi->next = current->next;
                current->next = exmplocheredi;
              }
          }
        if (!ukazatel || data.prior <= ukazatel->data.prior) {
            ukazatel = exmplocheredi;
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
