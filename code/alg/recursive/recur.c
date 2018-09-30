#include <stdio.h>
#include <stdlib.h>
#include <util.h>
#include "recur.h"

/**
 * 阶乘
 */
int factorial(int n)
{
    if (n == 0)
        return 1;
    else {
        int recurse = factorial(n-1);
        int result = n * recurse;
        return result;
    }
}

/**
 * 汉诺塔
 */
void hano(char a, char b, char c, int n)
{
    if (n <= 0) return;

    hano(a, c, b, n-1);
    move(a, c);
    hano(b, a, c, n-1);
}

void move(char a, char b)
{
    printf("%c->%c\n", a, b);
}


/**
 * 全排列算法，k为起始位置，n为数组大小
 */
void permute(int a[], int k, int n)
{
    if (k == n-1) {
        printIntArray(a, n); //输出排列
    } else {
        int i;
        for (i = k; i < n; i++) {
            swapInt(a, i, k); //交换
            permute(a, k+1, n); //下一次排列
            swapInt(a, i, k); //恢复原来的序列
        }
    }
}


/*
 * 组合主函数，包括选取1到n个数字
 */ 
void combination(int a[], int n)
{
    int *select = (int *)calloc(sizeof(int), n);
    int k;
    for (k = 1; k <= n; k++) {
        combinationUtil(a, n, 0, k, select);
    }
}

/*
 * 组合工具函数：从数组a从位置i开始选取k个数
 */
void combinationUtil(int a[], int n, int i, int k, int *select)
{
    if (i > n) return; //位置超出数组范围直接返回，否则非法访问会出段错误

    if (k == 0) {  //选取完了，输出选取的数字
        int j;
        for (j = 0; j < n; j++) {
            if (select[j])
                printf("%d ", a[j]);
        }
        printf("\n");
    } else {
        select[i] = 1;  
        combinationUtil(a, n, i+1, k-1, select); //第i个数字被选取，从后续i+1开始选取k-1个数
        select[i] = 0;
        combinationUtil(a, n, i+1, k, select); //第i个数字不选，则从后续i+1位置开始还要选取k个数
    }
}

/**
 * 逆序打印字符串
 */
void reversePrint(const char *str) 
{
    if (!*str)
        return;

    reversePrint(str + 1);
    putchar(*str);
}
