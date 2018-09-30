#include <stdio.h>
#include <util.h>
#include "recur.h"

void testFactorial()
{
    int n = 5;
    int r = factorial(n);
    printf("Factorial(%d): %d\n", n, r);
}

void testHano()
{
    printf("Hano:\n");
    int n = 3;
    hano('A', 'B', 'C', n);
}

void testPermute()
{
    printf("Permute:\n");
    int a[] = {1, 2, 3};
    int n = ALEN(a);
    permute(a, 0, n);
}

void testCombination()
{
    printf("Combination:\n");
    int a[] = {1, 2, 3};
    int n = ALEN(a);
    combination(a, n);
}

void testReversePrint()
{
    const char *str = "hello world";
    printf("Reverse print:%s\n", str);
    reversePrint(str);
    printf("\n");
}

int main()
{
    testFactorial();
    testHano();
    testPermute();
    testCombination();
    testReversePrint();
    return 0;
}
