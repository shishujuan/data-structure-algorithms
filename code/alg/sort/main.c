#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include "sort.h"

void testGeneralSort(void(*func)(int a[], int n), int a[], int n)
{
    func(a, n);
    printIntArray(a, n);
}

void testMergeSort(int a[], int n)
{
    mergeSort(a, 0, n-1);
    printIntArray(a, n);
}

void testSort()
{
    int a[] = {1, 3, 2, 4, 2, 0, 5, 0, 8, 7};
    int n = ALEN(a);

    testGeneralSort(insertSort, a, n);
    testGeneralSort(shellSort, a, n);
    testGeneralSort(selectSort, a, n);
    testGeneralSort(bubbleSort, a, n);
    testGeneralSort(betterBubbleSort, a, n);
    testGeneralSort(countingSort, a, n);
    testGeneralSort(mergeSortIter, a, n);

    testMergeSort(a, n);
}

int main()
{
    testSort();
    return 0;
}
