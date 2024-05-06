// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
 T data[20] = {};
    int start = 0;
    int ind = 0;

 public:
 T pop() {
 start += 1;
 return data[start - 1];
    }
 void push(T elem) {
 data[ind] = elem;
 ind += 1;
        for (int i = start; i < ind; i++) {
            for (int j = start; j < ind - 1; j++) {
                if ((data[j + 1].prior) > (data[j].prior)) {
 T tec = data[j];
 data[j] = data[j + 1];
 data[j + 1] = tec;
                }
            }
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
