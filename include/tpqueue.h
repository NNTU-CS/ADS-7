// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    T* arr;
    int begin, end;
    const int SIZE = 100;

 public:
    TPQueue() {
        begin = 0;
        end = 0;
        arr = new T[SIZE];
    }
    ~TPQueue() {
        delete[] arr;
    }
    int getSize() {
        return end - begin;
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
    void push(const T& item) {
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
        begin--;
        return arr[begin - 1];
    }
    T getElem(int indx) {
        return arr[indx]
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
