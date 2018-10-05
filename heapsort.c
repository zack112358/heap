#include "heapsort.h"

static size_t left_child(size_t parent) {
    return 2 * parent + 1;
}

static size_t right_child(size_t parent) {
    return 2 * parent + 2;
}

static size_t parent(size_t child) {
    return (child - 1) / 2;
}

static void swap(int *l, int *r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}

/**
 * Fix a maxheap whose root element is out of place.
 * Precondition: left child is the root of a valid heap if present.
 * Precondition: right child is the root of a valid heap if present.
 * Postcondition: root is the root of a valid heap.
 * @param array The array in which the heap resides
 * @param heap_len The # of elements in the heap
 * @param root The index of the root of the (sub)heap to fix
**/
static void heap_fix(int *array, size_t heap_len, size_t root) {
    size_t left = left_child(root);
    size_t right = right_child(root);
    if (right < heap_len) {
        if (array[root] < array[left] || array[root] < array[right]) {
            if (array[left] > array[right]) {
                swap(&array[left], &array[root]);
                heap_fix(array, heap_len, left);
            } else {
                swap(&array[right], &array[root]);
                heap_fix(array, heap_len, right);
            }
        }
    } else if (left < heap_len) {
        if (array[root] < array[left]) {
            swap(&array[root], &array[left]);
        }
        // No need to fix recursively because left child is last elt of list and
        // therefore has no children.
    } else {
        return; // nothing to fix, no children
    }
}

static void heap_pop(int *array, size_t *heap_len) {
    swap(&array[0], &array[*heap_len - 1]);
    *heap_len -= 1;
    heap_fix(array, *heap_len, 0);
}

void simple_heapsort(int *array, size_t array_len) {
    size_t heap_len = array_len;
    for (int root = heap_len - 1; root >= 0; --root) {
        heap_fix(array, heap_len, root);
    }
    while (heap_len > 0) {
        heap_pop(array, &heap_len);
    }
}
