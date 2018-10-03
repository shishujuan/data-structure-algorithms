#include <stdio.h>
#include <util.h>
#include "number.h"

void testPrimeGeneration()
{
    int n = 100;
    primeGeneration(n);
}

void testNumOfZero()
{
    int n = 10;
    int num = numOfZero(n);
    printf("NumOfZero(%d): %d\n", n, num);
    num = numOfZero(n);
    printf("NumOfZero2(%d): %d\n", n, num);
}

void testNumOfOne()
{
    int n = 123;
    int num = numOfOne(n);
    printf("NumOfOne(%d): %d\n", n, num);
}

void testFindContinuousSequence()
{
    int n = 15;
    printf("FindSequence(%d):\n", n);
    findContinuousSequence(n);
    printf("FindSequenceEndIndex(%d):\n", n);
    findContinuousSequenceEndIndex(n);
}

void testMaxSumOfContinousSequence()
{
    int a[] = {1, 3, -2, 4, -5};
    int n = ALEN(a);
    int maxSum = maxSumOfContinuousSequence(a, n);
    printf("MaxSumOfContinousSequence: %d\n", maxSum);
    maxSum = maxSumOfContinuousSequenceSub(a, 0, n-1);
    printf("MaxSumOfContinousSequenceSub: %d\n", maxSum);
    maxSum = maxSumOfContinuousSequenceEndIndex(a, n);
    printf("MaxSumOfContinousSequenceEndIndex: %d\n", maxSum);
}

void testMaxMultipleOfContinuousSequence()
{
    int a[] = {3, -4, -5, 6, -2};
    int n = ALEN(a);
    int maxMultiple = maxMultipleOfContinuousSequence(a, n);
    printf("MaxMultipleOfContinousSequence: %d\n", maxMultiple);
}

void testPowOf2()
{
    int a = 100;
    int b = 64;
    int ra = powOf2(a);
    int rb = powOf2(b);
    printf("PowOf2 %d:%d, %d:%d\n", a, ra, b, rb);
}

void testNumOfBit1()
{
    int a = 32;
    int b = 11;
    int ra = numOfBit1(a);
    int rb = numOfBit1(b);
    printf("NumOfBit1 %d:%d, %d:%d\n", a, ra, b, rb);
    ra = numOfBit1WithCheck(a);
    rb = numOfBit1WithCheck(b);
    printf("NumOfBit1WithCheck %d:%d, %d:%d\n", a, ra, b, rb);
}

void testReverseBit()
{
    uint a = 18;
    uint ra = reverseXOR(a);
    printf("ReverseBit: %s -> %s\n", bin(a), bin(ra));
    uint b = 19;
    uint rb = reverseXOR(b);
    printf("ReverseMask: %s -> %s\n", bin(b), bin(rb));
}

int main()
{
    testPrimeGeneration();
    testNumOfZero();
    testNumOfOne();
    testFindContinuousSequence();
    testMaxSumOfContinousSequence();
    testMaxMultipleOfContinuousSequence();
    testPowOf2();
    testNumOfBit1();
    testReverseBit();
    return 0;
}
