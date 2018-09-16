#ifndef __HEAP_H
#define __HEAP_H

#define PARENT(i) ( i >= 1 ? (i-1)/2 : 0)
#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)

typedef struct PriorityQueue {
    int capacity;
    int size;
    int elems[];
} PQ;

void maxHeapify(int A[], int i, int heapSize);
void buildMaxHeap(int A[], int n);
void heapSort(int A[], int n);

PQ *newPQ(int A[], int n);
void printPQ(PQ *pq);
int maximum(PQ *pq);
int extractMax(PQ *pq);
PQ *insert(PQ *pq, int key);
void increaseKey(PQ *pq, int i, int key);

#endif
