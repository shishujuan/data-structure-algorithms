#include <stdlib.h>
#include <util.h>
#include <stack.h>
#include "sort.h"

/**
 * 插入排序
 */
void insertSort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        /*
         * 循环不变式：a[0...i-1]有序。每次迭代开始前，a[0...i-1]有序，
         * 循环结束后i=n，a[0...n-1]有序
         * */
        int key = a[i];
        for (j = i; j > 0 && a[j-1] > key; j--) {
            a[j] = a[j-1];
        }
        a[j] = key;
    }
}


/**
 * 插入排序-另外一种实现
 */
void insertSortSwap(int a[], int l, int u) 
{ 
    int i, j;
    for (i = l; i < u; i++) { 
        for (j = i+1; j>l && a[j-1]>a[j]; j--) 
            swapInt(a, j, j-1); 
    }
}

/**
 * 希尔排序
 */
void shellSort(int a[], int n)
{
    int gap;
    for (gap = n/2; gap > 0; gap /= 2) {
        int i;
        for (i = gap; i < n; i++) {
            int key = a[i], j;
            for (j = i; j >= gap && key < a[j-gap]; j -= gap) {
                a[j] = a[j-gap];
            }
            a[j] = key;
        }
    }
}

/**
 * 选择排序
 */
void selectSort(int a[], int n)
{
    int i, j, min, tmp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            tmp = a[i], a[i] = a[min], a[min] = tmp; //交换a[i]和a[min]
    }
}

/**
 * 冒泡排序-经典版
 */
void bubbleSort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = n-1; j >= i+1; j--) {
            if (a[j] < a[j-1])
                tmp = a[j], a[j] = a[j-1], a[j-1] = tmp;
        }
    }
}

/**
 * 冒泡排序-优化版
 */
void betterBubbleSort(int a[], int n)
{
    int tmp, i, j;
    for (i = 0; i < n; i++) {
        int sorted = 1;
        for (j = n-1; j >= i+1; j--) {
            if (a[j] < a[j-1]) {
                tmp = a[j], a[j] = a[j-1], a[j-1] = tmp;
                sorted = 0;
            }   
        }   
        if (sorted)
            return ;
    }   
}

/**
 * 计数排序
 */
void countingSort(int a[], int n) 
{
    int i, j;
    int *b = (int *)malloc(sizeof(int) * n);
    int k = maxOfIntArray(a, n); // 求数组最大元素
    int *c = (int *)malloc(sizeof(int) * (k+1));  //辅助数组

    for (i = 0; i <= k; i++)
        c[i] = 0;

    for (j = 0; j < n; j++)
        c[a[j]] = c[a[j]] + 1; //c[i]包含等于i的元素个数

    for (i = 1; i <= k; i++)
        c[i] = c[i] + c[i-1];  //c[i]包含小于等于i的元素个数

    for (j = n-1; j >= 0; j--) {
        b[c[a[j]]-1] = a[j]; //结果存在b[0...n-1]中
        c[a[j]] = c[a[j]] - 1;
    }

    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }

    free(b);
    free(c);
}


/*
 * 归并排序-递归
 * */
void mergeSort(int a[], int l, int u) 
{
    if (l < u) {
        int m = l + (u-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, u);
        merge(a, l, m, u);
    }
}
 
/**
 * 归并排序合并函数
 */
void merge(int a[], int l, int m, int u) 
{
    int n1 = m - l + 1;
    int n2 = u - m;

    int left[n1], right[n2];
    int i, j;
    for (i = 0; i < n1; i++) /* left holds a[l..m] */
        left[i] = a[l + i];

    for (j = 0; j < n2; j++) /* right holds a[m+1..u] */
        right[j] = a[m + 1 + j];

    i = j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < n1) /* left[] is not exhausted */
        a[k++] = left[i++];
    while (j < n2) /* right[] is not exhausted */
        a[k++] = right[j++];
}

/**
 * 归并排序-非递归
 */
void mergeSortIter(int a[], int n)
{
    int i, s=2;
    while (s <= n) {
        i = 0;
        while (i+s <= n){
            merge(a, i, i+s/2-1, i+s-1);
            i += s;
        }

        //处理末尾残余部分
        merge(a, i, i+s/2-1, n-1);
        s*=2;
    }
    //最后再从头到尾处理一遍
    merge(a, 0, s/2-1, n-1);
}

/**
 * 快速排序-朴素版本
 */
void quickSort(int a[], int l, int u)
{
    if (l >= u) return;

    int q = partition(a, l, u);
    quickSort(a, l, q-1);
    quickSort(a, q+1, u);
}

/**
 * 快速排序-划分函数
 */
int partition(int a[], int l, int u)
{
    int i, q=l;
    for (i = l+1; i <= u; i++) {
        if (a[i] < a[l])
            swapInt(a, i, ++q);
    }
    swapInt(a, l, q);
    return q;
}

/**
 * 快速排序-双向划分法
 */
void quickSortLR(int a[], int l, int u)
{
    if (l >= u) return;

    int pivot = a[l];
    int q = partitionLR(a, l, u, pivot);
    quickSortLR(a, l, q-1);
    quickSortLR(a, q+1, u);
}

/**
 * 快速排序-双向划分函数
 */
int partitionLR(int a[], int l, int u, int pivot)
{
    int i = l;
    int j = u+1;
    while (1) {
        do {
            i++;
        } while (a[i] < pivot && i <= u); //注意i<=u这个判断条件，不能越界。

        do {
            j--;
        } while (a[j] > pivot);

        if (i > j) break;

        swapInt(a, i, j);
    }

    // 注意这里是交换l和j，而不是l和i，因为i与j交叉后，a[i...u]都大于等于枢纽元t，
    // 而枢纽元又在最左边，所以不能与i交换。只能与j交换。
    swapInt(a, l, j);

    return j;
}

/**
 * 快速排序-随机枢纽元版本
 */
void quickSortLRRandom(int a[], int l, int u)
{ 
    if (l >= u) return;

    int pivot = pivotRandom(a, l, u);
    int p = partitionLR(a, l, u, pivot);
    quickSortLRRandom(a, l, p-1); 
    quickSortLRRandom(a, p+1, u);
}


/**
 * 随机选择枢纽元
 */
int pivotRandom(int a[], int l, int u)
{
    int rand = randInt(l, u);
    swapInt(a, l, rand);
    return a[l];
}


/**
 * 快速排序-三数取中作为枢纽元版本
 */
void quickSortLRMedian3(int a[], int l, int u)
{ 
    if (l >= u) return;

    int pivot = pivotMedian3(a, l, u);
    int p = partitionLR(a, l, u, pivot);

    quickSortLRMedian3(a, l, p-1); 
    quickSortLRMedian3(a, p+1, u);
}

/**
 * 三数取中选择枢纽元
 */
int pivotMedian3(int a[], int l, int u)
{
     int m = l + (u-l)/2;

     /*
      * 三数排序
      */
     if( a[l] > a[m] )
        swapInt(a, l, m);

     if( a[l] > a[u] )
        swapInt(a, l, u);

     if( a[m] > a[u] )
        swapInt(a, m, u);

     /* assert: a[l] <= a[m] <= a[u] */
     swapInt(a, m, l); //交换枢纽元到位置l

     return a[l]; //返回枢纽元
}

/**
 * 快速排序-非递归版本
 */
void quickSortIter(int a[], int n)
{
    Stack *stack = stackNew(n);
    int l = 0, u = n-1;
    int p = partition(a, l, u);

    if (p-1 > l) { //左半部分两个边界值入栈
        push(stack, p-1); 
        push(stack, l);
    }

    if (p+1 < u) { //右半部分两个边界值入栈
        push(stack, u);
        push(stack, p+1);
    }

    while (!IS_EMPTY(stack)) { //栈不为空，则循环划分过程
        l = pop(stack);
        u = pop(stack);
        p = partition(a, l, u);

        if (p-1 > l) {
            push(stack, p-1);
            push(stack, l);
        }

        if (p+1 < u) {
            push(stack, u);
            push(stack, p+1);
        }
    }
}
