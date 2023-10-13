#include "../CuTest/CuTest.h"

#include "../src/ArrayList/array_list.h"

void TestArrayListSizeEmptyList(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);

    CuAssertIntEquals(tc, alSize(list), 0);

    deleteArrayList(list);
}

void TestArrayListSizeBeforeRealloc(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 7;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }

    CuAssertIntEquals(tc, alSize(list), n);

    deleteArrayList(list);
}

void TestArrayListSizeAfterRealloc(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 100;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }

    CuAssertIntEquals(tc, alSize(list), n);

    deleteArrayList(list);
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

    deleteArrayList(list);
}

void TestArrayListAt(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 32;
    for (int i = 0; i < n; i++) {
        alAdd(list, i * 2);
    }

    for (int i = 0, ei = alSize(list); i < ei; i++) {
        CuAssertIntEquals(tc, alAt(list, i), i * 2);
    }
    deleteArrayList(list);
}

void print_int(void* x) {
    printf("%d", (int) x);
}

void TestArrayListRemove(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 32;
    for (int i = 0; i < n; i++) {
        alAdd(list, i);
    }
    printf("Before remove: ");
    alPrint(list, print_int);
    int remove_count = 10;
    int remove_index = 5;
    for (int i = 0; i < remove_count; i++) {
        CuAssertTrue(tc, alRemove(list, remove_index));
    }
    printf("After remove:  ");
    alPrint(list, print_int);
    for (int i = 0; i < remove_index; i++) {
        CuAssertIntEquals(tc, alAt(list, i), i);
    }
    for (int i = remove_index, ei = alSize(list); i < ei; i++) {
        CuAssertIntEquals(tc, alAt(list, i), i + remove_count);
    }
    CuAssertIntEquals(tc, alSize(list), n - remove_count);
    deleteArrayList(list);
}

CuSuite* CuGetArrayListSuite() {
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, TestArrayListSizeEmptyList);
    SUITE_ADD_TEST(suite, TestArrayListSizeBeforeRealloc);
    SUITE_ADD_TEST(suite, TestArrayListSizeAfterRealloc);
    SUITE_ADD_TEST(suite, TestArrayListClear);
    SUITE_ADD_TEST(suite, TestArrayListAt);
    SUITE_ADD_TEST(suite, TestArrayListRemove);

    return suite;
}