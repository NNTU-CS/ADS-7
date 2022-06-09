// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    int count = 0;
    struct ITEM {
        T data;
        ITEM* next;
    };
    ITEM* head;
    ITEM* create(const T& data) {
        ITEM* item = new ITEM;
        item->data = data;
        item->next = nullptr;
        return item;
    }

 public:
    void push(T item) {
        count++;
        if (head) {
            ITEM* temp = create(item);
            temp->next = head;
            head = temp;
        } else {
            head = create(item);
        }
        CheckThisOut();
        Bratiki();
    }
    void CheckThisOut() {
        ITEM* tmp1 = head;
        ITEM* tmp2 = head->next;
        while (tmp2) {
            if (tmp2->data.prior >= tmp1->data.prior) {
                char ch = tmp1->data.ch;
                int pr = tmp1->data.prior;
                tmp1->data.ch = tmp2->data.ch;
                tmp1->data.prior = tmp2->data.prior;
                tmp2->data.ch = ch;
                tmp2->data.prior = pr;
            }
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
    }
    void Bratiki() {
        int flag = count;
        while (flag) {
            ITEM* tmp1 = head;
            ITEM* tmp2 = head->next;
            while (tmp2) {
                if (tmp2->data.prior == tmp1->data.prior) {
                    char ch = tmp1->data.ch;
                    int pr = tmp1->data.prior;
                    tmp1->data.ch = tmp2->data.ch;
                    tmp1->data.prior = tmp2->data.prior;
                    tmp2->data.ch = ch;
                    tmp2->data.prior = pr;
                }
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
            }
            flag -= 1;
        }
    }
    T pop() {
        ITEM* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
