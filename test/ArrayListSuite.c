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

void TestArrayListClear(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 100;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }

    CuAssertIntEquals(tc, alSize(list), n);
    alClear(list);
    CuAssertIntEquals(tc, alSize(list), 0);
}

void TestArrayListAt(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 100;
    for (int i = 0; i < n; i++) {
        alAdd(list, i * 2);
    }

    for (int i = 0, ei = alSize(list); i < ei; i++) {
        CuAssertIntEquals(tc, alAt(list, i), i * 2);
    }
}

CuSuite* CuGetArrayListSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestArrayListSizeEmptyList);
    SUITE_ADD_TEST(suite, TestArrayListSizeBeforeRealloc);
    SUITE_ADD_TEST(suite, TestArrayListSizeAfterRealloc);
    SUITE_ADD_TEST(suite, TestArrayListClear);
    SUITE_ADD_TEST(suite, TestArrayListAt);

    return suite;
}