#ifndef C_COLLECTIONS_ARRAY_LIST_H
#define C_COLLECTIONS_ARRAY_LIST_H

#include "array_list_internal.h"

/**
 * Resizable-array of generic type
 */
#define ArrayList(T) _array_list(T)

/**
 * Constructs an empty list with an initial capacity of eight.
 */
#define newArrayList(T) _new_array_list(T)

/**
 * Destroy this list
 *
 * @param this this list
 */
#define deleteArrayList(this) __delete_array_list(this)

/**
 * Appends the specified element to the end of this list.
 *
 * @param this this list
 * @param value element to be appended to this list
 */
#define alAdd(this, value) _al_add(this, value)

/**
 * Removes the element at the specified position in this list.
 * Shifts any subsequent elements to the left (subtracts one from their
 * indices).
 *
 * @param this this list
 * @param index the index of the element to be removed
 * @return true if the removing was successful, otherwise false
 */
#define alRemove(this, index) _al_remove(this, index)

/**
 * Returns the element at the specified position in this list.
 *
 * @param this this list
 * @param index index of the element to return
 * @return the element at the specified position in this list
 */
#define alAt(this, index) _al_at(this, index)

/**
 * Returns {@code true} if this list contains the specified element.
 *
 * @param this this list
 * @param element element whose presence in this list is to be tested
 * @param comparator function to compare two elements
 * @return {@code true} if this list contains the specified element
 */
#define alContains(this, element, comparator) _al_contains(this, element, comparator)

/**
 * Returns the number of elements in this list.
 *
 * @param this this list
 * @return the number of elements in this list
 */
#define alSize(this) __al_size(this)

/**
 * Removes all of the elements from this list.  The list will
 * be empty after this call returns.
 *
 * @param this this list
 */
#define alClear(this) __al_clear(this)

/**
 * Print a string representation of this list
 *
 * @param this this list
 * @param print_element list item print function
 */
#define alPrint(this, print_element) _al_print(this, print_element)

#endif //C_COLLECTIONS_ARRAY_LIST_H
