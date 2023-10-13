#ifndef HASH_MAP_ARRAY_LIST_H
#define HASH_MAP_ARRAY_LIST_H

#include <stdio.h>

struct __base_list;

/**
 * Resizable-array of generic type
 */
#define array_list(type) \
    struct {             \
        int __size;      \
        int __capacity;  \
        type* __data;    \
    } *

struct __base_list* __new_array_list(int element_size);

/**
 * Destroy this list
 *
 * @param this this list
 */
void delete_array_list(struct __base_list* this);

/**
 * Returns the number of elements in this list.
 *
 * @param this this list
 * @return the number of elements in this list
 */
int al_size(struct __base_list* this);

/**
 * Print a string representation of this list
 *
 * @param this this list
 * @param print_element list item print function
 */
#define al_print(this, print_element)                                        \
    printf("[");                                                             \
    if (this->__size > 0) {                                                  \
        typeof(*this->__data)* data = (typeof(*this->__data)*) this->__data; \
        print_element((void*) data[0]);                                      \
        for (int i = 1, ei = this->__size; i < ei; i++) {                    \
            printf(", ");                                                    \
            print_element((void*) data[i]);                                  \
        }                                                                    \
    }                                                                        \
    printf("]\n")

/**
 * Constructs an empty list with an initial capacity of eight.
 */
#define new_array_list(type) (array_list(type)) __new_array_list(sizeof(type))

void __al_resize(struct __base_list* this, int new_capacity, int element_size);

/**
 * Appends the specified element to the end of this list.
 *
 * @param this this list
 * @param value element to be appended to this list
 */
#define al_add(this, value)                                     \
    if (this->__size == this->__capacity) {                     \
        __al_resize(this, this->__capacity * 2, sizeof(value)); \
    }                                                           \
    this->__data[this->__size] = value;                         \
    this->__size++

/**
 * Returns the element at the specified position in this list.
 *
 * @param this this list
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
#define al_at(this, index) this->__data[index]

#endif //HASH_MAP_ARRAY_LIST_H
