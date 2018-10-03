#ifndef __UTIL_H
#define __UTIL_H

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

char *substr(char *s, int start, int n);
void swapInt(int a[], int i, int j);
void swapChar(char a[], int i, int j);
void printIntArray(int a[], int len);
void printCharArray(char a[], int len);

int max(int a, int b);
int max3(int a, int b, int c);
int min(int a, int b);
int min3(int a, int b, int c);
char *bin(int x);

int maxOfIntArray(int a[], int len);
int randInt(int l, int u);

int *copyIntArray(int a[], int n);

#endif
