#include <stdio.h>
#include <util.h>
#include "heap.h"

int main()
{
    printf("Build max heap: \n");
    int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    buildMaxHeap(a, ALEN(a));
    printIntArray(a, ALEN(a));

    printf("Heapsort:\n");
    int b[] = {1, 3, 2, 4, 5, 6};
    printIntArray(b, ALEN(b));
    heapSort(b, ALEN(b));
    printIntArray(b, ALEN(b));

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
