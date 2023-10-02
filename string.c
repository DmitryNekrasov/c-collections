#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "string.h"
#include "constants.h"

#define BASE 31

struct string {
    int length;
    int hash_code;
    const char* data;
};

int hash_code_internal(const char* c_str, int length) {
    int h = 0;
    for (int i = 0; i < length; i++) {
        h = BASE * h + c_str[i];
    }
    return h;
}

struct string* init_string(const char* c_str) {
    struct string* str = (struct string*) malloc(sizeof (struct string));
    str->data = c_str;
    str->length = (int) strlen(c_str);
    str->hash_code = hash_code_internal(c_str, str->length);
    return str;
}

void destroy_string(struct string* str) {
    free(str);
}

int equals(const struct string* str1, const struct string* str2) {
    if (str1 == str2) return TRUE;
    if (str1 == NULL || str2 == NULL) return FALSE;
    if (str1->length != str2->length || str1->hash_code != str2->hash_code) return FALSE;
    for (int i = 0, ei = str1->length; i < ei; i++) {
        if (str1->data[i] != str2->data[i]) return FALSE;
    }
    return TRUE;
}

void print_string(const struct string* this) {
    printf("%s", this->data);
}

int length(const struct string* this) {
    return this->length;
}

int hash_code(const struct string* this) {
    return this->hash_code;
}

const char* c_str(const struct string* this) {
    return this->data;
}