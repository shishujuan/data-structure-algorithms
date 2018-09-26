#include "bsearch.h"

/**
 * 基本二分查找算法
 */
int binarySearch(int a[], int n, int t)
{
    int l = 0, u = n - 1;
    while (l <= u) {
        int m = l + (u - l) / 2; // 同（l+u）/ 2，这里是为了溢出
        if (t > a[m])
            l = m + 1;
        else if (t < a[m])
            u = m - 1;
        else
            return m;
    }
    return -(l+1);
}

/**
 * 二分查找第一次出现位置
 */
int binarySearchFirst(int a[], int n, int t)
{
    int l = -1, u = n;
    while (l + 1 != u) {
        /*循环不变式a[l]<t<=a[u] && l<u*/
        int m = l + (u - l) / 2; //同（l+u）/ 2
        if (t > a[m])
            l = m;
        else
            u = m;
    }
    /*assert: l+1=u && a[l]<t<=a[u]*/
    int p = u;
    if (p>=n || a[p]!=t)
        p = -1;
    return p;
}

/**
 * 二分查找最后一次出现位置
 */
int binarySearchLast(int a[], int n, int t)
{
    int l = -1, u = n;
    while (l + 1 != u) {
        /*循环不变式, a[l] <= t < a[u]*/
        int m = l + (u - l) / 2;
        if (t >= a[m])
            l = m;
        else
            u = m;
    }
    /*assert: l+1 = u && a[l] <= t < a[u]*/
    int p = l;
    if (p<=-1 || a[p]!=t)
        p = -1;
    return p;
}

/**
 * 二分查找第一次和最后一次出现位置
 */
int binarySearchFirstAndLast(int a[], int n, int t, int firstFlag)
{
    int l = 0;
    int u = n - 1;
    while(l <= u) {
        int m = l + (u - l) / 2;
        if(a[m] == t) { //找到了，判断是第一次出现还是最后一次出现
            if(firstFlag) { //查询第一次出现的位置
                if(m != 0 && a[m-1] != t)
                    return m;
                else if(m == 0)
                    return 0;
                else
                    u = m - 1;
            } else {   //查询最后一次出现的位置
                if(m != n-1 && a[m+1] != t)
                    return m;
                else if(m == n-1)
                    return n-1;
                else
                    l = m + 1;
            }
        }
        else if(a[m] < t)
            l = m + 1;
        else
            u = m - 1;
    }

    return -1;
}

/**
 * 旋转数组查找-两次二分查找
 */
int binarySearchRotateTwice(int a[], int n, int t)
{
    int p = findRotatePosition(a, n); //找到旋转位置
    if (p == -1)
        return binarySearchFirst(a, n, t); //如果原数组有序，则直接二分查找即可

    int left = binarySearchFirst(a, p+1, t); //查找左半部分
    if (left != -1)
        return left; //左半部分找到，则直接返回

    int right = binarySearchFirst(a+p+1, n-p-1, t); //左半部分没有找到，则查找右半部分
    if (right == -1)
        return -1;

    return right+p+1;  //返回位置，注意要加上p+1
}

/**
 * 查找旋转位置
 */
int findRotatePosition(int a[], int n)
{
    int i;
    for (i = 0; i < n-1; i++) {
        if (a[i+1] < a[i])
            return i;
    }
    return -1;
}

/**
 * 旋转数组二分查找-一次二分查找
 */
int binarySearchRotateOnce(int a[], int n, int t)
{
    int l = 0, u = n-1;
    while (l <= u) {
        int m = l + (u-l) / 2;
        if (t == a[m])
            return m;
        if (a[m] >= a[l]) { //数组左半有序
            if (t >= a[l] && t < a[m])
                u = m - 1;
            else
                l = m + 1;
        } else {       //数组右半段有序
            if (t > a[m] && t <= a[u])
                l = m + 1;
            else
                u = m - 1;
        }   
    }   
    return -1; 
}
