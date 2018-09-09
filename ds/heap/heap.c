#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include "heap.h"

void maxHeapify(Heap *heap, int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int heapSize = heap->size;
    int *a = heap->elem;

    int largest = i;

    if (l <= heapSize-1 && a[l] > a[i]) {
        largest = l;
    }

    if (r <= heapSize-1 && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        swapInt(a, i, largest);
        maxHeapify(heap, largest);
    }
}

Heap *buildMaxHeap(int a[], int size)
{
    Heap *heap = heapInit(size);

    int i;
    for (i = 0; i < size; i++) {
        heap->elem[i] = a[i];
    }

    for (i = (size / 2 - 1); i >= 0; i--) {
        maxHeapify(heap, i);
    }
    return heap;
}

Heap *heapInit(int size)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap) + sizeof(int) * size);
    heap->size = size;
    return heap;
}

void heapAddElem(Heap *heap, int key)
{
    int newSize = heap->size + 1;
    heap = realloc(heap, sizeof(Heap) + sizeof(int) * newSize);
    heap->size = newSize;
    heap->elem[newSize - 1] = key;

    int i = newSize - 1;
    int *elem = heap->elem;
    while (i > 0 && elem[PARENT(i)] < elem[i]) {
        swapInt(elem, i, PARENT(i));
        i = PARENT(i);
    }
}
