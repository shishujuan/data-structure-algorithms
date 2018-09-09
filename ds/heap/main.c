#include <stdio.h>
#include <util.h>
#include "heap.h"

int main()
{
    int a[] = {1, 3, 2, 4, 5, 6};
    int len = ALEN(a);
    printIntArray(a, len);
    Heap *heap = buildMaxHeap(a, len);
    printIntArray(heap->elem, heap->size);

    Heap *initHeap = heapInit(0);

    int i;
    for (i = 0; i < len; i++) {
        heapAddElem(initHeap, a[i]);
    }
    printIntArray(initHeap->elem, initHeap->size);
}
