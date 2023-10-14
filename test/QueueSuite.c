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

CuSuite* CuGetQueueSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestQueue);

    return suite;
}