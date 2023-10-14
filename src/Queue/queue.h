#ifndef C_COLLECTIONS_QUEUE_H
#define C_COLLECTIONS_QUEUE_H

#include "queue_internal.h"

/**
 * FIFO queue of generic type
 */
#define Queue(T) _queue(T)

/**
 * Constructs an empty queue with an initial capacity of eight.
 */
#define newQueue(T) _new_queue(T)

/**
* Destroy this queue
*
* @param this this queue
*/
#define deleteQueue(this) __delete_queue(this)

/**
 * Inserts the specified element into this queue
 *
 * @param this this queue
 * @param element to be appended to this queue
 */
#define qOffer(this, value) _q_offer(this, value)

/**
 * Returns the number of elements in this queue.
 *
 * @param this this queue
 * @return the number of elements in this queue
 */
#define qSize(this) __q_size(this)

#endif //C_COLLECTIONS_QUEUE_H
