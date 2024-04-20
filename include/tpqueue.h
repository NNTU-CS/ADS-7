// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    Node* head;
 public:
    TPQueue() : head(nullptr) {}
    void push(SYM sim) {
        Node* newSim = new Node{ sim, nullptr };
        if (!head || sim.prior > head->data.prior) {
            newSim->next = head;
            head = newSim;
        } else {
            Node* last = head;
            while (last->next && sim.prior <= last->next->data.prior) {
                last = last->next;
            }
            newSim->next = last->next;
            last->next = newSim;
        }
    }

    SYM pop() {
        if (!head) {
            std::cerr << "Queue is empty!" << std::endl;
            return SYM();
        }
        SYM data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }
};

struct SYM {
  char ch;
  int prior;
};
struct Node {
  SYM data;
  Node* next;
};
#endif  // INCLUDE_TPQUEUE_H_
