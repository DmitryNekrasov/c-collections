#include <stdio.h>

#include "CuTest/CuTest.h"

CuSuite* CuGetArrayListSuite();

void RunAllTests() {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, CuGetArrayListSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main() {
    RunAllTests();
    return 0;
}