// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
    struct ITEM {
        T value;
        ITEM* next;
    };
public:
    TPQueue() :head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T&);
    T pop();
    void print() const;
private:
    TPQueue::ITEM* create(const T&);
    ITEM* head;
    ITEM* dop;
    ITEM* tail;
};  
  // реализация шаблона очереди с приоритетом на связанном списке
template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& value)
{
    ITEM* item = new ITEM;
    item->value = value;
    item->next = nullptr;
    return item;
}
template<typename T>
TPQueue<T>::~TPQueue()
{
    while (head)
        pop();
}
template<typename T>
void TPQueue<T>::push(const T& inf) {
    if (head == nullptr) {
        head = create(inf);
        dop = head;
        tail = head;
    }
    else if (tail->value.prior >= inf.prior) {
        if (tail->value.prior == inf.prior && tail->value.ch == inf.ch) { 
            tail->value = inf;
        }
        else {
            if (tail->value.prior >= inf.prior && tail->value.ch != inf.ch) {
                tail->next = create(inf);
                tail = tail->next;
            }
        }
    }
    else {
        if (tail->value.prior < inf.prior) {
            if (inf.prior > head->value.prior) {
                ITEM* tmp = NULL;
                tmp = create(inf);
                tmp->next = head;
                head = tmp;
            }
            else 
               if (inf.prior == head->value.prior) {
                 if (inf.ch == head->value.ch)
                   head->value = inf;
               }
            else {
               ITEM* dop = nullptr;
               dop = create(inf);
               dop->next = head->next;
               head->next = dop;
            }
            else {
               if (inf.prior < head->value.prior) {
                 ITEM* dop = nullptr;
                 dop = create(inf);
                 dop->next = head->next;
                 head->next = dop;
               }
            }
        }
    }
}
template<typename T>
T TPQueue<T>::pop() {
    if (head) {
        ITEM* temp = head->next;
        T value = head->value;
        delete head;
        head = temp;
        return value;
    }    
}
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
