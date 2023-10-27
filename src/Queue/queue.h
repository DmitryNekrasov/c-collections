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
 * Retrieves and removes the head of this queue,
 * or returns {@code null} if this queue is empty.
 *
 * @param this this queue
 * @return the head of this queue, or {@code null} if this queue is empty
 */
#define qPoll(this) _q_poll(this)

/**
 * Returns the number of elements in this queue.
 *
 * @param this this queue
 * @return the number of elements in this queue
 */
#define qSize(this) __q_size(this)

/**
 * Returns {@code true} if this queue contains no elements.
 *
 * @param this this queue
 * @return {@code true} if this queue contains no elements
 */
#define qIsEmpty(this) __q_is_empty(this)

/**
 * Print a string representation of this queue in debug format
 *
 * @param this this queue
 * @param print_element queue item print function
 */
#define qPrintDebug(this, print_element) _q_print_debug(this, print_element)

#endif //C_COLLECTIONS_QUEUE_H
