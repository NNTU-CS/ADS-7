// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
    SYM* next_node;
    SYM* prev_node;
};

template <typename T = SYM>
class TPQueue {
    // реализация шаблона очереди с приоритетом на связанном списке
 private:
    SYM* rear;
    SYM* front;
    int size;

 public:
    TPQueue() : size(0), rear(nullptr), front(nullptr) {}
    void push(SYM n) {
        if (size == 0) {
            front = new SYM;
            front->ch = n.ch;
            front->prior = n.prior;
            front->next_node = front->prev_node = nullptr;
            rear = front;
            size++;
            return;
        } else {
            SYM* temp = rear;
            if (n.prior <= temp->prior) {
                SYM* x = new SYM;
                x->ch = n.ch;
                x->prior = n.prior;
                x->prev_node = x->next_node = nullptr;
                temp->next_node = x;
                temp->next_node->prev_node = temp;
                rear = temp->next_node;
                size++;
                return;
            } else if (n.prior > front->prior) {
                SYM* x = new SYM;
                x->ch = n.ch;
                x->prior = n.prior;
                x->prev_node = x->next_node = nullptr;
                x->next_node = front;
                front->prev_node = x;
                front = x;
                size++;
                return;
            } else {
                SYM* y = front;
                while (y->next_node && n.prior <= y->prior) {
                    y = y->next_node;
                }
                SYM* x = new SYM;
                x->ch = n.ch;
                x->prior = n.prior;
                x->prev_node = x->next_node = nullptr;
                x->next_node = y;
                x->prev_node = y->prev_node;
                y->prev_node = x;
                x->prev_node->next_node = x;
                size++;
            }
        }
    }

    SYM pop() {
        if (size == 0) {
            SYM n{ '0', -2 };
            return n;
        } else {
            SYM temp;
            temp.ch = front->ch;
            temp.prior = front->prior;
            front = front->next_node;
            size--;
            return temp;
        }
    }
};
#endif  // INCLUDE_TPQUEUE_H_
