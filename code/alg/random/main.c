#include <stdio.h>
#include <util.h>
#include "random.h"

void testRandomNtimes(void (*func)(int a[], int n), int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        func(a, n);
        printIntArray(a, n);
    }
}

void testRandomArray()
{
    int a[] = {1, 2, 3};
    int n = ALEN(a);

    testRandomNtimes(randomInPlace, a, n);

    int b[] = {4, 5, 6};
    n = ALEN(b);
    testRandomNtimes(permuteWithAll, b, n);
}

void testRandomOne()
{
    int i, n = 5;
    for (i = 0; i < n; i++) {
        printf("RandomOne(%d): ", i);
        randomOne(i);
    }
}

void testRandomM()
{
    int n = 5, m = 2;
    printf("RandomMKnuth(%d, %d): ", n, m);
    randomMKnuth(n, m);
    printf("RandomMArray(%d, %d): ", n, m);
    randomMArray(n, m);
}

void testRandom7ToRand10()
{
    printf("Rand7ToRand10 Sample: %d\n", rand7ToRand10Sample());
    printf("Rand7ToRand10 Utilize Sample: %d\n", rand7ToRand10UtilizeSample());
}

int main()
{
    testRandomArray();
    testRandomOne();
    testRandomM();
    testRandom7ToRand10();
    return 0;
}
