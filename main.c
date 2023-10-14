#include <stdio.h>

#include "CuTest/CuTest.h"

CuSuite* CuGetArrayListSuite();
CuSuite* CuGetQueueSuite();

void RunAllTests() {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, CuGetArrayListSuite());
    CuSuiteAddSuite(suite, CuGetQueueSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main() {
    RunAllTests();
    return 0;
}