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
    TQueue() {
        begin = 0;
        end = 0;
        count = 0;
        arr = new T[SIZE];
    }
    ~TQueue() {
        delete[] arr;
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
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
