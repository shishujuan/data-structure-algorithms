#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <util.h>

/**
 * 数组的均匀随机排列: 每个排列出现概率相等。
 */
void randomInPlace(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        int rand = randInt(i, n-1);
        swapInt(a, i, rand);
    }
}

/**
 * 错误示范：全排列，注意每个排列的概率并不相等。
 */
void permuteWithAll(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        int rand = randInt(0, n-1);
        swapInt(a, i, rand);
    }
}

/**
 * 未知长度的序列中随机选取一个数
 */
void randomOne(int n)
{
    int i, select = 0;
    for (i = 1; i < n; i++) {
        int rd = rand() % n;
        if (rd == 0) {
            select = i;
        }
    }
    printf("%d\n", select);
}

/**
 * n个数中随机选取m个有序数-knuth算法
 */
void randomMKnuth(int n, int m)
{
    int i;
    for (i = 0; i < n; i++) {
        if ((rand() % (n-i)) < m) {
            printf("%d ", i);
            m--;
        }
    }
    printf("\n");
}

/**
 * n个数随机选取m个有序数-随机数组法
 */
void randomMArray(int n, int m)
{
    int i, j;
    int *x = (int *)malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++)
        x[i] = i;

    for (i = 0; i < m; i++) {
        j = randInt(i, n-1);
        swapInt(x, i, j);
    }

    for (i = 0; i < m; i++) {
        for (j = i+1; j>0 && x[j-1]>x[j]; j--) {
            swapInt(x, j, j-1);
        }
    }

    for (i = 0; i < m; i++) {
        printf("%d ", x[i]);
    }

    printf("\n");
}

/**
 * 从rand7 得到 rand10
 */
int rand7ToRand10Sample() {
    int row, col, idx;
    do {
        row = randInt(1, 7);
        col = randInt(1, 7);
        idx = col + (row-1)*7;
    } while (idx > 40);

    return 1 + (idx-1) % 10;
}

/**
 * 从rand7 得到 rand10-优化方法
 */
int rand7ToRand10UtilizeSample() {
    int a, b, idx;
    while (1) {
        a = randInt(1, 7);
        b = randInt(1, 7);
        idx = b + (a-1)*7;
        if (idx <= 40)
            return 1 + (idx-1)%10;

        a = idx-40;
        b = randInt(1, 7);
        // get uniform dist from 1 - 63
        idx = b + (a-1)*7;
        if (idx <= 60)
            return 1 + (idx-1)%10;

        a = idx-60;
        b = randInt(1, 7);
        // get uniform dist from 1-21
        idx = b + (a-1)*7;
        if (idx <= 20)
            return 1 + (idx-1)%10;
    }
}
