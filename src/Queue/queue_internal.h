#ifndef C_COLLECTIONS_QUEUE_INTERNAL_H
#define C_COLLECTIONS_QUEUE_INTERNAL_H

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

#define _new_queue(type) (_queue(type)) __new_queue(sizeof(type));

void __delete_queue(struct __base_queue* this);

#endif //C_COLLECTIONS_QUEUE_INTERNAL_H
