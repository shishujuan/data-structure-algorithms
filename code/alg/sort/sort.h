#ifndef __SORT_H
#define __SORT_H

void insertSort(int a[], int n);
void shellSort(int a[], int n);
void selectSort(int a[], int n);
void bubbleSort(int a[], int n);
void betterBubbleSort(int a[], int n);
void countingSort(int a[], int n);

void mergeSortIter(int a[], int n);
void mergeSort(int a[], int l, int u);
void merge(int a[], int l, int m, int u);

int partition(int a[], int l, int u);
int partitionLR(int a[], int l, int u, int pivot);
int pivotRandom(int a[], int l, int u);
int pivotMedian3(int a[], int l, int u);
void quickSort(int a[], int l, int u);
void quickSortLR(int a[], int l, int u);
void quickSortLRRandom(int a[], int l, int u);
void quickSortLRMedian3(int a[], int l, int u);
void quickSortIter(int a[], int n);

#endif
