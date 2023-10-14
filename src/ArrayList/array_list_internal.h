#ifndef HASH_MAP_ARRAY_LIST_INTERNAL_H
#define HASH_MAP_ARRAY_LIST_INTERNAL_H

#include <stdio.h>
#include <stdbool.h>

struct __base_list;

#define _array_list(type) \
    struct {              \
        int __size;       \
        int __capacity;   \
        type* __data;     \
    } *

struct __base_list* __new_array_list(int element_size);

void __delete_array_list(struct __base_list* this);

int __al_size(struct __base_list* this);

#define _al_print(this, print_element)                                        \
    printf("[");                                                              \
    if (this->__size > 0) {                                                   \
        typeof(*this->__data)* data = (typeof(*this->__data)*) this->__data;  \
        print_element((void*) data[0]);                                       \
        for (int i = 1, ei = this->__size; i < ei; i++) {                     \
            printf(", ");                                                     \
            print_element((void*) data[i]);                                   \
        }                                                                     \
    }                                                                         \
    printf("]\n")

#define _new_array_list(type) (_array_list(type)) __new_array_list(sizeof(type))

void __al_resize(struct __base_list* this, int new_capacity, int element_size);

#define _al_add(this, value)                                     \
    if (this->__size == this->__capacity) {                      \
        __al_resize(this, this->__capacity * 2, sizeof(value));  \
    }                                                            \
    this->__data[this->__size] = value;                          \
    this->__size++

#define _al_at(this, index) this->__data[index]

void __al_clear(struct __base_list* this);

bool __al_remove(struct __base_list* this, int index, int element_size);

#define _al_remove(this, index) \
    ((index < 0 || index >= this->__size) ? false : __al_remove(this, index, sizeof(*this->__data)))

bool __al_contains(struct __base_list* this, void* element, int (*comparator)(void*, void*), int element_size);

#define _al_contains(this, element, comparator) __al_contains(this, (void*) element, comparator, sizeof(*this->__data))

#endif //HASH_MAP_ARRAY_LIST_INTERNAL_H
