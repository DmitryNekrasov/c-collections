#include "printers.h"

#include <stdio.h>

void print_int(void* x) {
    printf("%d", (int) x);
}

void print_char(void* x) {
    printf("%c", (char) x);
}
