#include "../CuTest/CuTest.h"

void TestArrayListSize(CuTest* tc) {
    CuAssertTrue(tc, 1);
}

CuSuite* CuGetArrayListSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestArrayListSize);

    return suite;
}