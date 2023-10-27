#ifndef C_COLLECTIONS_QUEUE_INTERNAL_H
#define C_COLLECTIONS_QUEUE_INTERNAL_H

#include <stdio.h>
#include <stdbool.h>

struct __base_queue;

#define _queue(type)      \
    struct {              \
        int __size;       \
        int __capacity;   \
        int __tail;       \
        int __head;       \
        type* __data;     \
    } *

struct __base_queue* __new_queue(int element_size);

#define _new_queue(type) (_queue(type)) __new_queue(sizeof(type))

void __delete_queue(struct __base_queue* this);

#define _q_offer(this, value)                             \
    if (this->__size == this->__capacity) {               \
    }                                                     \
    this->__data[this->__tail] = value;                   \
    this->__tail = (this->__tail + 1) % this->__capacity; \
    this->__size++

int __q_size(struct __base_queue* this);

bool __q_is_empty(struct __base_queue* this);

void* __q_poll(struct __base_queue* this, int element_size);

#define _q_poll(this) __q_poll(this, sizeof(*this->__data))

#define _q_print_debug(this, print_element)                              \
    printf("[");                                                         \
    typeof(*this->__data)* data = (typeof(*this->__data)*) this->__data; \
    int in_middle = this->__tail >= this->__head;                        \
    if (in_middle && (this->__head == 0) ||                              \
        !in_middle && (this->__tail > 0)) {                              \
        print_element((void*) this->__data[0]);                          \
    } else {                                                             \
        printf("_");                                                     \
    }                                                                    \
    for (int i = 1, ei = this->__capacity; i < ei; i++) {                \
        if (in_middle && (i >= this->__head && i < this->__tail) ||      \
            !in_middle && (i < this->__tail || i >= this->__head)) {     \
            printf(", ");                                                \
            print_element((void*) this->__data[i]);                      \
        } else {                                                         \
            printf(", _");                                               \
        }                                                                \
    }                                                                    \
    printf("]\n");

#endif //C_COLLECTIONS_QUEUE_INTERNAL_H
