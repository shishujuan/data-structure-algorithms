#include <stdlib.h>
#include <stdio.h>
#include "util.h"

/**
 * 工具函数-打印数组元素
 */
void printIntArray(int a[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }   
    printf("\n");
}

void printCharArray(char a[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%c ", a[i]);
    }   
    printf("\n");
}


/**
 * 工具函数-求子串
 */
char *substr(char *s, int start, int n)
{
    char *subs = (char *)malloc(n+1);
    int i = 0;

    while (i < n && *s != '\0') {
        subs[i] = s[start + i];
        ++i;
    }
    subs[i] = '\0';
    return subs;
}

/**
 * 工具函数-交换数组两个元素
 */
void swapInt(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swapChar(char a[], int i, int j)
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
