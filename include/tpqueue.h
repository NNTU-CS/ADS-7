// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
char ch;
int prior;
};

template<typename T>
class TPQueue {
 private:
struct point {
T inf;
point* next;
point(T zn){
inf = zn;
next = nullptr;
}
};

point* head;

 public:
TPQueue() {
head = nullptr;
}

void push(T znach) {
if (head == nullptr) {
head = new point(znach);
return;
}
point* count = head;
if (count->inf.prior < znach.prior) {
head = new point(znach);
head->next = count;
} else {
int f = 0;
while (count->next != nullptr) {
if (count->next->inf.prior < znach.prior) {
point* tmp = new point(znach);
tmp->next = count->next;
count->next = tmp;
f = 1;
break;
}
count = count->next;
}
if (f == 0) {
count->next = new point(znach);
}
}
}

T pop() {
point* count = head;
head = head->next;
return count->inf;
}

~TPQueue(){
point* del;
while(head != nullptr){
del = head;
head = head->next;
delete del;
}
}
};

#endif  // INCLUDE_TPQUEUE_H_
