// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  T arr[100] = {};
  int ind = 0, F = 0;

 public:
  T pop() {
    F += 1;
    return arr[F - 1];
  }

  void push(T elem) {
    arr[ind] = elem;
    ind += 1;
    for (int i = F; i < ind; i++) {
      for (int j = F; j < ind - 1; j++) {
        if (arr[j].prior < arr[j + 1].prior) {
          T boofer = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = boofer;
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
