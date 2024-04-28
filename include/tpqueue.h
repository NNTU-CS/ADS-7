// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct Patt {
        T data;
        Patt* next;
    };
    TPQueue::Patt *create(const T &);
    Patt* head;
    Patt* tail;
public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T &);
    T pop();
    void removeTail();
};
template<typename T>
typename TPQueue<T>::Patt *TPQueue<T>::create(const T &data) {
    Patt *pPatt = new Patt;
    pPatt->data = data;
    pPatt->next = nullptr;
    return pPatt;
}
template<typename T>
void TPQueue<T>::push(const T &data) {
    if (head == nullptr) {
        tail = create(data);
        head = tail;
    } else if (head == tail) {
        if (tail->data.prior < data.prior) {
            tail->next = create(data);
            tail = tail->next;
    } else {
        Patt *tempo = head;
        head = create(data);
        head->next = tempo;
    }
} else {
            Patt *temp = head;
            if (data.prior > tail->data.prior) {
                tail->next = create(data);
                tail = tail->next;
            } else if (data.prior < head->data.prior) {
                Patt *per = head;
                head = create(data);
                head->next = per;
            } else {
            while (data.prior > temp->next->data.prior) {
                temp = temp->next;
            }
            Patt *tem = tem->next;
            temp->next = create(data);
            temp->next->next=tem;
            }
    }
        }
        template<typename T>
        T TPQueue<T>::pop() {
            T temp = tail->data;
            removeTail();
            return temp;
        }
        template<typename  T>
        TPQueue<T>::~TPQueue() {
            while (tail) {
                pop();
            }
        }
        template<typename T>
        void TPQueue<T>::removeTail() {
            Patt *temp = head;
            if (head == tail) {
                delete tail;
                head = tail = nullptr;
            } else {
                while (temp->next !=tail) {
                    temp = temp->next;
                }
                temp->next = nullptr;
                delete tail;
                tail = temp;
            }
        }


struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
