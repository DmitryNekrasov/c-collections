#include "../CuTest/CuTest.h"

#include "../ArrayList/array_list.h"

void TestArrayListSizeEmptyList(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);

    CuAssertIntEquals(tc, alSize(list), 0);
}

void TestArrayListSizeBeforeRealloc(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 7;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }

    CuAssertIntEquals(tc, alSize(list), n);
}

void TestArrayListSizeAfterRealloc(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 100;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }

    CuAssertIntEquals(tc, alSize(list), n);
}

CuSuite* CuGetArrayListSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestArrayListSizeEmptyList);
    SUITE_ADD_TEST(suite, TestArrayListSizeBeforeRealloc);
    SUITE_ADD_TEST(suite, TestArrayListSizeAfterRealloc);

    return suite;
}