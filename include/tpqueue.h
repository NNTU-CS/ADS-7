// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  T data[18] = {};
  int index = 0, start = 0;
 public:
  T pop() {
    start += 1;
    return data[start - 1];
  }
  void push(T elem) {
    data[index] = elem;
    index += 1;
    for (int t = start; t < index; t++) {
      for (int i = start; i < index - 1; i++) {
        if ((data[i + 1].prior) > (data[i].prior)) {
          T b = data[i];
          data[i] = data[i + 1];
          data[i + 1] = b;
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
