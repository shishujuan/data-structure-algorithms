#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <util.h>
#include "number.h"

/**
 * 找出前N个素数, N > 3
 */
int primeGeneration(int n)
{
    int *prime = (int *)malloc(sizeof(int) * n);
    int gap = 2;            
    int count = 3;
    int maybePrime = 5;
    int i, isPrime;

    /* 注意：2, 3, 5 是素数 */
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;

    while (count < n)  {
         maybePrime += gap;
         gap = 6 - gap;
         isPrime = 1; 
         for (i = 2; prime[i]*prime[i] <= maybePrime && isPrime; i++)
              if (maybePrime % prime[i] == 0)
                   isPrime = 0;

         if (isPrime)
              prime[count++] = maybePrime;
    }

    printf("\nFirst %d Prime Numbers are :\n", count);

    for (i = 0; i < count; i++) {
         if (i % 10 == 0) printf("\n");
         printf("%5d", prime[i]);
    }
    printf("\n");
    return 0;
}

/**
 * N!末尾0的个数
 */
int numOfZero(int n)
{
    int cnt = 0, i, j;
    for (i = 1; i <= n; i++) {
        j = i;
        while (j % 5 == 0) {
            cnt++;
            j /= 5;
        }
    }
    return cnt;
}

/**
 * N!末尾0的个数-优化版
 */
int numOfZero2(int n)
{
    int cnt = 0;
    while (n) {
        cnt += n/5;
        n /= 5;
    }
    return cnt;
}


/**
 * 1-N正整数中1的个数
 */
int numOfOne(int n)
{
    int factor = 1, cnt = 0;  //factor为乘数因子
    int low = 0, curr = 0, high = 0;
    while (n / factor != 0) {
        low = n - n/factor * factor;  //low为低位数字，curr为当前考虑位的数字，high为高位数字
        curr = n/factor % 10;
        high = n/(factor * 10);

        switch(curr) {
            case 0:   //当前位为0的情况
                cnt += high * factor;
                break;
            case 1:   //当前位为1的情况
                cnt += high * factor + low + 1;
                break;
            default:  //当前位为其他数字的情况
                cnt += (high+1) * factor;
                break;
        }
        factor *= 10;
    }
    return cnt;
}


/**
 * 查找和为N的连续序列
 */
int findContinuousSequence(int n) 
{
    int found = 0;
    int k = 2, x, m, i;  // k为连续序列的数字的数目，x为起始的值，m用于判断是否有满足条件的值。
    while (1) { 
        x = (n - k*(k-1)/2) / k;  // 求出k个连续正整数和为n的起始值x
        m = (n - k*(k-1)/2) % k; // m用于判断是否有满足条件的连续正整数值

        if (x <= 0)
            break;    // 退出条件，如果x<=0，则循环退出。

        if (!m) {     // m为0，表示找到了连续子序列和为n。
            found = 1;
            printContinuousSequence(x, k);
        }
        k++;
    }
    return found;
}

/**
 * 查找和为N的连续序列-序列结尾位置法
 */
int findContinuousSequenceEndIndex(int n) 
{
    if (n < 3) return 0;

    int found = 0;
    int begin = 1, end = 2;
    int mid = (1 + n) / 2;
    int sum = begin + end;

    while (begin < mid) {
        if (sum > n) {
            sum -= begin;
            begin++;
        } else {
            if (sum == n) {
                found = 1;
                printContinuousSequence(begin, end-begin+1);
            }

            end++;
            sum += end;
        }
    }

    return found;
}

/**
 * 打印连续子序列
 */
void printContinuousSequence(int x, int k)
{
    int i;
    for (i = 0; i < k; i++) {
        printf("%d ", x++);
    }
    printf("\n");
}

/**
 * 最大连续子序列和
 */
int maxSumOfContinuousSequence(int a[], int n)
{
    int max = a[0], i, j, sum; // 初始化最大值为第一个元素
    for (i = 0; i < n; i++) {
        sum = 0; // sum必须清零
        for (j = i; j < n; j++) { //从位置i开始计算从i开始的最大连续子序列和的大小，如果大于max，则更新max。
            sum += a[j];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}

/**
 * 最大连续子序列和-分治法
 */
int maxSumOfContinuousSequenceSub(int a[], int l, int u)
{
    if (l > u) return 0;
    if (l == u) return a[l];
    int m = (l + u) / 2;

    /*求横跨左右的最大连续子序列左半部分*/
    int lmax = a[m], lsum = 0;
    int i;

    for (i = m; i >= l; i--) {
        lsum += a[i];
        if (lsum > lmax)
            lmax = lsum;
    }

    /*求横跨左右的最大连续子序列右半部分*/
    int rmax=a[m+1], rsum = 0;
    for (i = m+1; i <= u; i++) {
        rsum += a[i];
        if (rsum > rmax)
            rmax = rsum;
    }

    return max3(lmax+rmax, maxSumOfContinuousSequenceSub(a, l, m),
        maxSumOfContinuousSequenceSub(a, m+1, u)); //返回三者最大值
}

/**
 * 最大连续子序列和-结束位置法
 */
int maxSumOfContinuousSequenceEndIndex(int a[], int n)
{
    int maxSum, maxHere, i;
    maxSum = maxHere = a[0];   // 初始化最大和为a[0]

    for (i = 1; i < n; i++) {
        if (maxHere <= 0)
            maxHere = a[i];  // 如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]
        else
            maxHere += a[i]; // 如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和

        if (maxHere > maxSum) {
            maxSum = maxHere;  //更新最大连续子序列和
        }
    }
    return maxSum;
}

/**
 * 最大连续子序列乘积
 */
int maxMultipleOfContinuousSequence(int a[], int n)
{
    int minSofar, maxSofar, max, i;
    int maxHere, minHere;
    max = minSofar = maxSofar = a[0];

    for (i = 1; i < n; i++) {
        int maxHere = max3(maxSofar*a[i], minSofar*a[i], a[i]);
        int minHere = min3(maxSofar*a[i], minSofar*a[i], a[i]);
        maxSofar = maxHere, minSofar = minHere;
        if(max < maxSofar)
            max = maxSofar;
    }
    return max;
}

/**
 * 判断正整数是2的幂次
 */
int powOf2(int n)
{
    assert(n > 0);
    return !(n & (n-1));
}

/**
 * 二进制表示中1的个数-解法1
 */
int numOfBit1(int n)
{
    int cnt = 0;
    unsigned int flag = 1;
    while (flag) {
        if(n & flag)
            cnt++;

        flag = flag << 1;
        if (flag > n)
            break;
    }
    return cnt;
}

/**
 * 二进制表示中1的个数-解法2
 */
int numOfBit1WithCheck(int n)
{
    int cnt = 0;
    while (n != 0) {
        n = (n & (n-1));
        cnt++;
    }
    return cnt;
}

/**
 * 反转比特位
 */
uint swapBits(uint x, uint i, uint j)
{
    uint lo = ((x >> i) & 1);  // 取x的第i位的值
    uint hi = ((x >> j) & 1);  // 取x的第j位的值
    if (lo ^ hi) {             
        x ^= ((1U << i) | (1U << j)); // 如果第i位和第j位值不同，则交换i和j这两个位的值，使用异或操作实现
    }
    return x;
}
 
/**
 * 反转整数比特位-仿字符串反转
 */
uint reverseXOR(uint x)
{
    uint n = sizeof(x) * 8;
    uint i;
    for (i = 0; i < n/2; i++) {
        x = swapBits(x, i, n-i-1);
    }
    return x;
}

/**
 * 反转整数比特位-分治法
 */
uint reverseMask(uint x)
{
    assert(sizeof(x) == 4); // special case: only works for 4 bytes (32 bits).
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
    return x;
}
