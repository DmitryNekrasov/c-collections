#include "../CuTest/CuTest.h"

#include "../src/Queue/queue.h"

void TestQueue(CuTest* tc) {
    Queue(int) queue = newQueue(int);
    deleteQueue(queue);
}

CuSuite* CuGetQueueSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestQueue);

    return suite;
}