#ifndef __RECUR_H
#define __RECUR_H

int factorial(int n);
void hano(char a, char b, char c, int n);
void move(char a, char b);

void permute(int a[], int k, int n);

void combination(int a[], int n);
void combinationUtil(int a[], int n, int i, int k, int *select);

void reversePrint(const char *str);
#endif
