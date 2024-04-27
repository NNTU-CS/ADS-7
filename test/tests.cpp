// Copyright 2021 NNTU-CS
#include <gtest/gtest.h>
#include <string>
#include "tpqueue.h"

TEST(lab7, test1) {
TPQueue<SYM> pqueue;
pqueue.push(SYM{'a', 4});
pqueue.push(SYM{'b', 7});
pqueue.push(SYM{'c', 6});
pqueue.push(SYM{'d', 5});
pqueue.push(SYM{'e', 8});

SYM c1 = pqueue.pop();
SYM c2 = pqueue.pop();

pqueue.push(SYM{'f', 9});
pqueue.push(SYM{'g', 1});

SYM c3 = pqueue.pop();
SYM c4 = pqueue.pop();

ASSERT_EQ(c1.ch, 'e');
ASSERT_EQ(c2.ch, 'b');
ASSERT_EQ(c3.ch, 'f');
ASSERT_EQ(c4.ch, 'c');
}

TEST(lab7, test2) {
TPQueue<SYM> pqueue;
pqueue.push(SYM{'a', 4});
pqueue.push(SYM{'b', 4});
SYM c1 = pqueue.pop();
SYM c2 = pqueue.pop();
ASSERT_EQ(c1.ch, 'a');
ASSERT_EQ(c2.ch, 'b');
}

TEST(lab7, test3) {
TPQueue<SYM> pqueue;
pqueue.push(SYM{'a', 4});
pqueue.push(SYM{'b', 4});
pqueue.push(SYM{'c', 9});
SYM c1 = pqueue.pop();
SYM c2 = pqueue.pop();
SYM c3 = pqueue.pop();
ASSERT_EQ(c1.ch, 'c');
ASSERT_EQ(c2.ch, 'a');
ASSERT_EQ(c3.ch, 'b');
}
