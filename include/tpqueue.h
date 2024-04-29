// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    T arr[10] ={};
    int begin, end;

 public:
    int getSize() {
        return end - begin;
    }
    
    void push(T& item) {
        arr[end] = item;
        end++;
        int pe = end;
        for (int i = begin; i < end; i++) {
            for (int j = begin; j < end - 1; j++) {
                if (arr[j].prior < arr[j + 1].prior) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    T pop() {
        begin++;
        return arr[begin - 1];
    }
    bool isEmpty() {
        if (this->getSize() == 0)
            return true;
        return false;
    }
    bool isFull() {
        if (this->getSize() != 0)
            return true;
        return false;
    }
    T getElem(int indx) {
        return arr[indx];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
