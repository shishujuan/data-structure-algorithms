#ifndef __HEAP_H
#define __HEAP_H

#define PARENT(i) ((i-1) / 2)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct Heap {
    int size;
    int elem[];
} Heap;

void maxHeapify(Heap *heap, int i);
Heap *buildMaxHeap(int a[], int size);
void heapAddElem(Heap *heap, int key);
Heap *heapInit(int size);

#endif
