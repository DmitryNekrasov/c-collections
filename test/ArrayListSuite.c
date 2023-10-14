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

void TestArrayListRemoveFalse(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    alAdd(list, 7);
    CuAssertTrue(tc, !alRemove(list, 10));
    deleteArrayList(list);
}

int int_comparator(void* a, void* b) {
    return (int) a - (int) b;
}

void TestArrayListContains(CuTest* tc) {
    ArrayList(int) list = newArrayList(int);
    int n = 20;
    for (int i = 0; i < n; i++) {
        alAdd(list, i * 100000000);
    }
    CuAssertTrue(tc, alContains(list, 500000000, int_comparator));
    CuAssertTrue(tc, !alContains(list, 123, int_comparator));
    deleteArrayList(list);
}

void print_char(void* x) {
    printf("%c", (char) x);
}

int char_comparator(void* a, void* b) {
    return (char) a - (char) b;
}

void TestArrayListCharContains(CuTest* tc) {
    ArrayList(char) list = newArrayList(char);
    for (char c = 'a'; c <= 'z'; c++) {
        alAdd(list, c);
    }
    alPrint(list, print_char);
    CuAssertTrue(tc, alContains(list, 'x', char_comparator));
    CuAssertTrue(tc, !alContains(list, 'A', char_comparator));
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
    SUITE_ADD_TEST(suite, TestArrayListRemoveFalse);
    SUITE_ADD_TEST(suite, TestArrayListContains);
    SUITE_ADD_TEST(suite, TestArrayListCharContains);

    return suite;
}