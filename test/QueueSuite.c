#include "../CuTest/CuTest.h"

#include "../src/Queue/queue.h"

void TestQueue(CuTest* tc) {
    Queue(int) queue = newQueue(int);
    int n = 5;
    for (int i = 0; i < n; i++) {
        qOffer(queue, i);
    }
    CuAssertIntEquals(tc, qSize(queue), n);
    deleteQueue(queue);
}

void TestQueuePoll(CuTest* tc) {
    Queue(int) queue = newQueue(int);
    int n = 5;
    for (int i = 0; i < n; i++) {
        qOffer(queue, i);
    }
    for (int i = 0; i < n; i++) {
        int value = (int) qPoll(queue);
        CuAssertIntEquals(tc, i, value);
    }
    deleteQueue(queue);
}

void TestQueueIsEmpty(CuTest* tc) {
    Queue(int) queue = newQueue(int);
    CuAssertTrue(tc, qIsEmpty(queue));
    int n = 5;
    for (int i = 0; i < n; i++) {
        qOffer(queue, i);
    }
    CuAssertTrue(tc, !qIsEmpty(queue));
    for (int i = 0, ei = qSize(queue); i < ei; i++) {
        qPoll(queue);
    }
    CuAssertTrue(tc, qIsEmpty(queue));
    deleteQueue(queue);
}

CuSuite* CuGetQueueSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestQueue);
    SUITE_ADD_TEST(suite, TestQueuePoll);
    SUITE_ADD_TEST(suite, TestQueueIsEmpty);

    return suite;
}