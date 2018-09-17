#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <util.h>
#include "heap.h"

/**
 * 保持最大堆性质
 */
void maxHeapify(int A[], int i, int heapSize)
{
    int l = LEFT(i);
    int r = RIGHT(i);

    int largest = i;

    if (l <= heapSize-1 && A[l] > A[i]) {
        largest = l;
    }

    if (r <= heapSize-1 && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) { // 最大值不是i，则需要交换i和largest的元素，并递归调用maxHeapify。
        swapInt(A, i, largest);
        maxHeapify(A, largest, heapSize);
    }
}

/**
 * 从一个数组建一个最大堆
 */
void buildMaxHeap(int A[], int n)
{
    int i;
    for (i = n/2-1; i >= 0; i--) {
        maxHeapify(A, i, n);
    }
}

/**
 * 堆排序
 */
void heapSort(int A[], int n)
{
    buildMaxHeap(A, n);
    int heapSize = n;
    int i;
    for (i = n-1; i >= 1; i--) {
        swapInt(A, 0, i);
        maxHeapify(A, 0, --heapSize);
    }
}

/**
 * 从数组创建优先级队列
 */
PQ *newPQ(int A[], int n)
{
    PQ *pq = (PQ *)malloc(sizeof(PQ) + sizeof(int) * n);
    pq->size = 0;
    pq->capacity = n;

    int i;
    for (i = 0; i < pq->capacity; i++) {
        pq->elems[i] = A[i];
        pq->size++;
    }
    buildMaxHeap(pq->elems, pq->size);

    return pq;
}

/**
 * 打印优先级队列
 */
void printPQ(PQ *pq)
{
    int i;
    for (i = 0; i < pq->size; i++) {
        printf("%d ", pq->elems[i]);
    }
    printf("\n");
}


int maximum(PQ *pq)
{
    return pq->elems[0];
}

int extractMax(PQ *pq)
{
    int max = pq->elems[0];
    pq->elems[0] = pq->elems[--pq->size];
    maxHeapify(pq->elems, 0, pq->size);
    return max;
}

PQ *insert(PQ *pq, int key)
{
    int newSize = ++pq->size;
    if (newSize > pq->capacity) {
        pq->capacity = newSize * 2;
        pq = (PQ *)realloc(pq, sizeof(PQ) + sizeof(int) * pq->capacity);
    }
    pq->elems[newSize-1] = INT_MIN;
    increaseKey(pq, newSize-1, key);
    return pq;
}

void increaseKey(PQ *pq, int i, int key)
{
    int *elems = pq->elems;
    elems[i] = key;

    while (i > 0 && elems[PARENT(i)] < elems[i]) {
        swapInt(elems, PARENT(i), i);
        i = PARENT(i);
    }
}
