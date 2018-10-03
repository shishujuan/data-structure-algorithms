#ifndef __NUMBER_H
#define __NUMBER_H

typedef unsigned int uint;

int primeGeneration(int n);
int numOfZero(int n);
int numOfOne(int n);

int findContinuousSequence(int n);
void printContinuousSequence(int x, int k);
int findContinuousSequenceEndIndex(int n);

int maxSumOfContinuousSequence(int a[], int n);
int maxSumOfContinuousSequenceSub(int a[], int l, int u);
int maxSumOfContinuousSequenceEndIndex(int a[], int n);

int maxMultipleOfContinuousSequence(int a[], int n);

int powOf2(int n);
int numOfBit1(int n);
int numOfBit1WithCheck(int n);

uint swapBits(uint x, uint i, uint j);
uint reverseXOR(uint x);
uint reverseMask(uint x);

#endif
