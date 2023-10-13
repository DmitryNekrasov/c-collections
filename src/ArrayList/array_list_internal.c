#include <malloc.h>
#include <string.h>

#include "array_list_internal.h"

#define INITIAL_CAPACITY 8

struct __base_list {
    int __size;
    int __capacity;
    void* __data;
};

struct __base_list* __new_array_list(int element_size) {
    struct __base_list* list = (struct __base_list*) malloc(sizeof(struct __base_list));
    list->__size = 0;
    list->__capacity = INITIAL_CAPACITY;
    list->__data = malloc(element_size * list->__capacity);
    return list;
}

void __delete_array_list(struct __base_list* this) {
    free(this->__data);
    free(this);
}

int __al_size(struct __base_list* this) {
    return this->__size;
}

void __al_resize(struct __base_list* this, int new_capacity, int element_size) {
    void* new_data = malloc(element_size * new_capacity);
    memcpy(new_data, this->__data, this->__size * element_size);
    free(this->__data);
    this->__data = new_data;
    this->__capacity = new_capacity;
}

void __al_clear(struct __base_list* this) {
    this->__size = 0;
}

bool __al_remove(struct __base_list* this, int index, int element_size) {
    int n = this->__size;
    this->__size--;
    if (index == n - 1) return true;
    char* start_ptr = (((char*) this->__data) + index * element_size);
    memcpy(start_ptr, start_ptr + element_size, (n - index - 1) * element_size);
    return true;
}
