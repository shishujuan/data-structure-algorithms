#include <stdio.h>
#include <util.h>
#include "bsearch.h"

void testBinarySearch()
{
    int a[] = {1, 2, 4, 8, 8, 9, 12};
    int n = ALEN(a);
    int t = 8;
    int ret = binarySearch(a, n, t);
    printIntArray(a, n);
    printf("Binary Search: %d, result: %d\n", t, ret);
    ret = binarySearchFirst(a, n, t);
    printf("Binary Search First: %d, result: %d\n", t, ret);
    ret = binarySearchLast(a, n, t);
    printf("Binary Search Last: %d, result: %d\n", t, ret);
    ret = binarySearchFirstAndLast(a, n, t, 1);
    printf("Binary Search First: %d, result: %d\n", t, ret);
    ret = binarySearchFirstAndLast(a, n, t, 0);
    printf("Binary Search Last: %d, result: %d\n", t, ret);
}

void testBinarySearchRotate()
{
    int a[] = {3, 4, 5, 1, 2};
    int n = ALEN(a);
    int t = 5;
    printIntArray(a, n);
    int ret = binarySearchRotateTwice(a, n, t);
    printf("Binary Search Rotate(Twice): %d, result: %d\n", t, ret);
    ret = binarySearchRotateOnce(a, n, t);
    printf("Binary Search Rotate(Once): %d, result: %d\n", t, ret);
    t = 1;
    ret = binarySearchRotateTwice(a, n, t);
    printf("Binary Search Rotate(Twice): %d, result: %d\n", t, ret);
    ret = binarySearchRotateOnce(a, n, t);
    printf("Binary Search Rotate(Once): %d, result: %d\n", t, ret);
}

int main()
{
    testBinarySearch();
    testBinarySearchRotate();
    return 0;
}
