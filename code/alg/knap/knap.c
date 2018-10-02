#include <stdlib.h>
#include <stdio.h>
#include <util.h>
#include "knap.h"

/*
 * 01背包问题
 * N为物品数目，C为背包容量，w[i]为物品i的重量，v[i]为物品i的价值，f为结果列表
 */
int knap01(int N, int C, int w[], int v[])
{
    int *f = (int *)calloc(sizeof(int), C+1);
    int i, c;
    for (i = 0; i < N; i++) {
        for (c = C; c >= w[i]; c--) {
            f[c] = max(f[c], f[c-w[i]] + v[i]);
        }
        printf("%d: ", i+1);
        printIntArray(f, C+1);

    }
    return f[C];
}

/*
 * 完全背包问题
 */
int knapComplete(int N, int C, int w[], int v[])
{
    int *f = (int *)calloc(sizeof(int), C+1);
    int i, c, k;
    for (i = 0; i < N; i++) {
        for (c = C; c >= 0; c--) {
            for (k = 0; k <= c/w[i]; k++) {
                f[c] = max(f[c], f[c-k*w[i]] + k*v[i]);
            }
        }
        printf("%d: ", i+1);
        printIntArray(f, C+1);
    }
    return f[C];
}

/**
 * 完全背包问题-仿01背包解法
 */
int knapCompleteLike01(int N, int C, int w[], int v[])
{
    int *f = (int *)calloc(sizeof(int), C+1);
    int i, c;
    for (i = 0; i < N; i++) {
        for (c = w[i]; c <= C; c++) {
            f[c] = max(f[c], f[c-w[i]] + v[i]);
        }
        printf("%d: ", i+1);
        printIntArray(f, C+1);

    }
    return f[C];
}
