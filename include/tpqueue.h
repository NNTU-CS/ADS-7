// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
    struct Item {
        T data;
        Item* next;
    };
    Item* create(const T&);
    bool IsEmpty();
    Item* head;
    Item* tail;

 public:
    TPQueue();
    void rmHead();
    ~TPQueue();
    void push(T);
    T pop();
};
template<typename T>
void TPQueue<T>::rmHead() {
    if (head && tail) {
        Item* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        if (!head) {
            tail = nullptr;
        }
    }
}
template <typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& data) {
    Item* item = new Item;
    item->data = data;
    item->next = nullptr;
    return item;
}
template<typename T>
bool TPQueue<T>::IsEmpty() {
    return head == nullptr;
}
template<typename T>
TPQueue<T>::TPQueue() {
    head = tail = nullptr;
}
template<typename T>
TPQueue<T>::~TPQueue() {
    if (head) {
        rmHead();
    }
}
template<typename T>
void TPQueue<T>::push(T sym) {
    if (IsEmpty()) {
        head = tail = create(sym);
    } else {
        Item* beg = head;
        Item* temp = create(sym);
        if (head->data.prior < temp->data.prior) {
            temp->next = head;
            head = temp;
        } else {
            while (beg->next && beg->next->data.prior >= temp->data.prior) {
                beg = beg->next;
            }
            temp->next = beg->next;
            beg->next = temp;
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    if (head && tail) {
        Item* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        if (!head) {
            tail = nullptr;
        }
        return data;
    } else {
        return { '\0',-1 };
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
