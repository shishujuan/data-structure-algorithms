#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include "sort.h"

void testGeneralSort(void(*func)(int a[], int n), int a[], int n)
{
    int *b = copyIntArray(a, n);
    func(b, n);
    printIntArray(b, n);
}

void testMergeSort(int a[], int n)
{
    int *b = copyIntArray(a, n);
    mergeSort(b, 0, n-1);
    printIntArray(b, n);
}

void testQuickSort(void(*func)(int a[], int l, int u), int a[], int n)
{
    int *b = copyIntArray(a, n);
    func(b, 0, n-1);
    printIntArray(b, n);
}

void testSort()
{
    int a[] = {1, 3, 2, 4, 2, 5, 8, 7};
    int n = ALEN(a);

    testGeneralSort(insertSort, a, n);
    testGeneralSort(shellSort, a, n);
    testGeneralSort(selectSort, a, n);
    testGeneralSort(bubbleSort, a, n);
    testGeneralSort(betterBubbleSort, a, n);
    testGeneralSort(countingSort, a, n);
    testGeneralSort(mergeSortIter, a, n);
    testGeneralSort(quickSortIter, a, n);

    testMergeSort(a, n);

    testQuickSort(quickSort, a, n);
    testQuickSort(quickSortLR, a, n);
    testQuickSort(quickSortLRRandom, a, n);
    testQuickSort(quickSortLRMedian3, a, n);
}

int main()
{
    testSort();
    return 0;
}
