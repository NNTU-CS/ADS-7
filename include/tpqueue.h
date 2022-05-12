// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
struct ITEM {
T zn;
ITEM* pr, * sl;
};
ITEM* gl, * hv, * rnow;
TPQueue::ITEM* create(const T& zn) {
ITEM* item = new ITEM;
item->zn = zn;
item->sl = nullptr;
item->pr = nullptr;
return item;
}

 public:
TPQueue() {
gl = hv = rnow = nullptr;
}
~TPQueue() {
while (gl)
pop();
}
T getNext() {
if (hv && gl) {
if (!rnow)
rnow = gl;
else if (rnow->sl)
rnow = rnow->sl;
else
throw std::string("Beyond border");
return rnow->zn;
}
else {
throw std::string("Beyond border");
}
}
T pop() {
if (hv && gl) {
ITEM* tmp = gl->sl;
if (tmp)
tmp->pr = nullptr;
T zn = gl->zn;
delete gl;
gl = tmp;
if (!gl)
hv = nullptr;
return zn;
} else {
throw std::string("Out of limit!");
}
}
void push(const T& zn) {
ITEM* tmp = gl;
ITEM* item = create(zn);
while (tmp && tmp->zn.prior >= zn.prior)
tmp = tmp->sl;
if (!tmp && gl) {
hv->sl = item;
item->pr = hv;
hv = item;
} else if (!tmp && !gl) {
gl = hv = item;
} else if (!tmp->pr) {
gl->pr = item;
item->sl = gl;
gl = item;
} else {
tmp->pr->sl = item;
item->pr = tmp->pr;
item->sl = tmp;
tmp->pr = item;
}
}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
