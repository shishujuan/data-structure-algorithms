#include <stdio.h>
#include <util.h>
#include "heap.h"

int main()
{
    int a[] = {1, 3, 2, 4, 5, 6};
    int n = ALEN(a);

    buildMaxHeap(a, n);
    printIntArray(a, n);

    int b[] = {1, 3, 2, 4, 5, 6};
    printIntArray(b, ALEN(b));
    heapSort(b, n);
    printIntArray(b, n);

    int c[] = {1, 3, 2, 4, 5, 6};
    printIntArray(c, ALEN(c));
    PQ *pq = newPQ(c, ALEN(c));
    printf("PQ max: %d\n", maximum(pq));
    printPQ(pq);
    printf("PQ extractMax: %d\n", extractMax(pq));
    printPQ(pq);
    pq = insert(pq, 8);
    printPQ(pq);
}
