#ifndef __BINARY_SEARCH_H
#define __BINARY_SEARCH_H

int binarySearch(int a[], int n, int t);
int binarySearchFirst(int a[], int n, int t);
int binarySearchLast(int a[], int n, int t);
int binarySearchFirstAndLast(int a[], int n, int t, int firstFlag);

int findRotatePosition(int a[], int n);
int binarySearchRotateTwice(int a[], int n, int t);
int binarySearchRotateOnce(int a[], int n, int t);

#endif
