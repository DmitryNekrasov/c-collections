#include <malloc.h>

#include "queue_internal.h"

#define INITIAL_CAPACITY 8

struct __base_queue {
    int __size;
    int __capacity;
    int __tail;
    int __head;
    void* __data;
};

struct __base_queue* __new_queue(int element_size) {
    struct __base_queue* queue = (struct __base_queue*) malloc(sizeof(struct __base_queue));
    queue->__size = 0;
    queue->__capacity = INITIAL_CAPACITY;
    queue->__tail = 0;
    queue->__head = 0;
    queue->__data = malloc(queue->__capacity * element_size);
    return queue;
}

void __delete_queue(struct __base_queue* this) {
    free(this->__data);
    free(this);
}

int __q_size(struct __base_queue* this) {
    return this->__size;
}

bool __q_is_empty(struct __base_queue* this) {
    return this->__size == 0;
}

void* __q_poll(struct __base_queue* this, int element_size) {
    if (__q_is_empty(this)) return NULL;
    const char* data = (const char*) this->__data;
    void* element = (void*) *(data + this->__head * element_size);
    this->__head = (this->__head + 1) % this->__capacity;
    this->__size--;
    return element;
}
