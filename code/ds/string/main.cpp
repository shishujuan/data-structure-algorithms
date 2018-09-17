#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
using namespace std;

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

int matchstar(int c, const char *regexp, const char *text);
int matchhere(const char *regexp, const char *text);


/****************/
/**最长回文子串**/
/****************/

/**
 * 判断字符串s[start:end]是否是回文字符串
 */
int isPalindrome(string s, int start, int end) 
{
    for (; start < end; ++start,--end) {
        if (s[start] != s[end])
            return 0;
    }
    return 1;
}

/**
 * 最长回文子串-蛮力法 O(N^3)
 */
string longestPalindrome(string s)
{
    int len = s.length(), maxLen = 1;
    int start=0, i, j;

    /*遍历字符串所有的子串，若子串为回文字符串则更新最长回文的长度*/
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (isPalindrome(s, i, j)) { //如果str[i,j]是回文，则判断其长度是否大于最大值，大于则更新长度和位置
                int pLen = j - i + 1;
                if (pLen > maxLen) {
                    start = i;  //更新最长回文起始位置
                    maxLen = pLen; //更新最长回文的长度
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

/**
 * 最长回文子串-动态规划法,该方法的时间复杂度为O(N^2)，空间复杂度为O(N^2)。
 *
 * 思想：定义P[i, j] = 1 如果子串P[i, j]是回文字符串。
 * 则 P[i, j] <- (P[i+1, j-1] && s[i] == s[j])。
 *
 * Base Case:
 * P[ i, i ] <- 1 
 * P[ i, i+1 ] <- s[i] == s[i+1]
 */
string longestPalindromeDP(string s)
{
    int n = s.length();
    int longestBegin = 0, maxLen = 1;

    int **P;
    int i;

    /*构造二维数组P*/
    P = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++) {
        P[i] = (int *)calloc(n, sizeof(int));
    }


    for (i = 0; i < n; i++) {
        P[i][i] = 1;
    }

    for (int i=0; i<n-1; i++) {
        if (s[i] == s[i+1]) {
            P[i][i+1] = 1;
            longestBegin = i;
            maxLen = 2;
        }
    }

    /*依次求P[i][i+2]...P[i][i+n-1]等*/
    int len = 3;
    for (; len <= n; ++len) {
        for (i = 0; i < n-len+1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && P[i+1][j-1]) {
                P[i][j] = 1;
                longestBegin = i;
                maxLen = len;
            }
        }
    }

    /*释放内存*/
    for (i = 0; i< n; i++)
        free(P[i]);
    free(P);

    return s.substr(longestBegin, maxLen);
}

/**
 * 求位置l为中心的最长回文子串的开始位置和长度
 */
void expandAroundCenter(string s, int l, int r, int *longestBegin, int *longestLen)
{
    int n = s.length();
    while (l>=0 && r<=n-1 && s[l]==s[r]) {
        l--, r++;
    }

    *longestBegin = l + 1;
    *longestLen = r - l - 1;
}
 
/**
 * 最长回文子串-中心法，时间O(N^2)。
 */
string longestPalindromeCenter(string s)
{
    int n = s.length();
    if (n == 0) 
        return s;

    char longestBegin = 0;
    int longestLen = 1;

    for (int i = 0; i < n; i++) {
        int iLongestBegin, iLongestLen;
        expandAroundCenter(s, i, i, &iLongestBegin, &iLongestLen); //以位置i为中心的最长回文字符串
        if (iLongestLen > longestLen) {
            longestLen = iLongestLen;
            longestBegin = iLongestBegin;
        }
 
        expandAroundCenter(s, i, i+1, &iLongestBegin, &iLongestLen); //以i和i+1之间的位置为中心的最长回文字符串
        if (iLongestLen > longestLen) {
            longestLen = iLongestLen;
            longestBegin = iLongestBegin;
        }
    }
    return s.substr(longestBegin, longestLen);
}

/**
 * 最长回文子串测试函数
 */
void testLongestPalindrome()
{
    string s = "abcbaef";
    printf("String:%s LongestPalindrome: %s\n", s.c_str(), longestPalindrome(s).c_str());
    printf("String:%s LongestPalindromeDP: %s\n", s.c_str(), longestPalindromeDP(s).c_str());
    printf("String:%s LongestPalindromeCenter: %s\n", s.c_str(), longestPalindromeCenter(s).c_str());

    string s2 = "abba";
    printf("String:%s LongestPalindrome: %s\n", s2.c_str(), longestPalindrome(s2).c_str());
    printf("String:%s LongestPalindromeDP: %s\n", s2.c_str(), longestPalindromeDP(s2).c_str());
    printf("String:%s LongestPalindromeCenter: %s\n", s2.c_str(), longestPalindromeCenter(s2).c_str());
}


/****************/
/**** RGB排序 ***/
/****************/

void swapChar(char *s, int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

/**
 * 划分函数
 */
void partition(char *s, int lo, int hi, char t)
{
    int m = lo-1, i;
    for (i = lo; i <= hi; i++) {
        if (s[i] != t) {
            swapChar(s, ++m ,i);
        }
    }
}
 
/**
 * RGB排序-遍历两次
 */
void rgbSortTwice(char *s)
{ 
    int len = strlen(s);
    partition(s, 0, len-1, 'G');  // 以G划分，划分完为 RBBRBBGGGG
    partition(s, 0, len-1, 'B');  // 再以B划分，划分完为 RRGGGGBBBB
}

/**
 * RGB排序-遍历一次
 */
void rgbSortOnce(char *s)
{
    int len = strlen(s);
    int lo = 0, hi = len - 1;

    int r, g, i; //++r和++g分别指向R和G交换的位置
    r = g = lo - 1;

    for (i = lo; i <= hi; i++) {
        if (s[i] == 'R') {  // 遇到R
            swapChar(s, ++r, i);
            ++g;
            if (s[i] == 'G') // 交换后的值是G，继续交换
                swapChar(s, g, i);
        } else if (s[i] == 'G') { // 遇到G
            swapChar(s, ++g, i);
        } else {                   // 遇到B，什么都不做
        }
    }
}


/**
 * RGB排序测试函数
 */
void testRGBSort()
{
    char s[] = "RGBBRGGBGB";
    printf("Org:%s\n", s);
    rgbSortTwice(s);
    printf("Sorted:%s\n", s);
    char s2[] = "RGBBRGGBBGB";
    rgbSortOnce(s2);
    printf("SortedOnce:%s\n", s2);
}


/******************/
/** 最大滑动窗口 **/
/******************/

/*
 * 求数组最大值
 */
int maxInArray(int A[], int n)
{
    int max = A[0], i;
    for (i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

/*
 * 最大滑动窗口-简单实现
 */
void maxSlidingWindowSimple(int A[], int n, int w, int B[]) 
{
    int i;
    for (i = 0; i <= n-w; i++) 
        B[i] = maxInArray(A + i, w);
}

/**
 * 最大滑动窗口-最大堆解法
 */
void maxSlidingWindowPQ(int A[], int n, int w, int B[])
{
    typedef pair<int, int> Pair;
    priority_queue<Pair> Q; //优先级队列保存窗口里面的值

    for (int i = 0; i < w; i++)
        Q.push(Pair(A[i], i));  //构建w个元素的最大堆

    for (int i = w; i < n; i++) {
        Pair p = Q.top();
        B[i-w] = p.first;
        while (p.second <= i-w) {
           Q.pop();
           p = Q.top();
        }
        Q.push(Pair(A[i], i));
    }
    B[n-w] = Q.top().first;
}

/**
 * 最大滑动窗口-双向队列
 */
void maxSlidingWindowDQ(int A[], int n, int w, int B[])
{
    deque<int> Q;
    for (int i = 0; i < w; i++) {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    for (int i = w; i < n; i++) {
        B[i-w] = A[Q.front()];
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();

        while (!Q.empty() && Q.front() <= i-w)
            Q.pop_front();

        Q.push_back(i);
    }
    B[n-w] = A[Q.front()];
}

void printIntArray(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
/**
 * 最大滑动窗口测试函数
 */
void testMaxSlidingWindow()
{
    printf("Test MaxSlidingWindow:\n");
    int A[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int w = 3;
    int n = ALEN(A);
    int *B = (int *)calloc(sizeof(int), n);
    maxSlidingWindowSimple(A, n, w, B);
    printIntArray(B, n - w + 1);
    free(B);

    B = (int *)calloc(sizeof(int), n);
    maxSlidingWindowPQ(A, n, w, B);
    printIntArray(B, n - w + 1);
    free(B);

    B = (int *)calloc(sizeof(int), n);
    maxSlidingWindowDQ(A, n, w, B);
    printIntArray(B, n - w + 1);
    free(B);
}


/*****************/
/** 字符串全排列 */
/****************/
void perm(char *arr, int k, int len) { //k为起始位置，len为数组大小
    if (k == len-1) { 
        printf("%s\n", arr);
        return;
    }

    for (int i = k; i < len; i++) {
        swapChar(arr, i, k); //交换
        perm(arr, k+1, len); //下一次排列
        swapChar(arr, i, k); //恢复原来的序列
    }
}

void testPerm()
{
    printf("Test Perm:\n");
    char arr[] = "abc";
    perm(arr, 0, strlen(arr));
}


/********************/
/** 最长公共子序列 **/
/********************/

#define UP 1
#define LEFT 2
#define UPLEFT 3

/**
 * LCS-动态规划算法
 */
int lcsLength(char *X, char *Y, int **c, int **b)
{
    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = UPLEFT;
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = LEFT;
            }
        }
    }

    return c[m][n];
}

/**
 * LCS-递归算法
 */
int lcsLengthRecur(char *X, int m, char *Y, int n, int **b)
{
    if (m == 0 || n == 0)
        return 0;

    if (X[m-1] == Y[n-1]) {
        b[m][n] = UPLEFT;
        return lcsLengthRecur(X, m-1, Y, n-1, b) + 1;
    } 

    int len1 = lcsLengthRecur(X, m-1, Y, n, b);
    int len2 = lcsLengthRecur(X, m, Y, n-1, b);

    int maxLen;
    if (len1 >= len2) {
        maxLen = len1;
        b[m][n] = UP;
    } else {
        maxLen = len2;
        b[m][n] = LEFT;
    }
    return maxLen;
}

/**
 * 打印LCS，用到辅助数组b
 */
void printLCS(int **b, char *X, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == UPLEFT) {
        printLCS(b, X, i-1, j-1);
        printf("%c ", X[i-1]);
    } else if (b[i][j] == UP) {
        printLCS(b, X, i-1, j);
    } else {
        printLCS(b, X, i, j-1);
    }
}

void testLCS()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    int lenX = strlen(X);
    int lenY = strlen(Y);

    int **b = (int **)calloc(sizeof(int *), lenX+1);
    for (int i = 0; i < lenX+1; i++) {
        b[i] = (int *)calloc(sizeof(int), lenY+1);
    }

    int **c = (int **)calloc(sizeof(int *), lenX+1);
    for (int i = 0; i < lenX+1; i++) {
        c[i] = (int *)calloc(sizeof(int), lenY+1);
    }

    printf("Test LCS:\n");
    // int lcsLen = lcsLength(X, Y, c, b);
    int lcsLen = lcsLengthRecur(X, lenX, Y, lenY, b);
    printf("lcsLen: %d\n", lcsLen);
    printLCS(b, X, lenX, lenY);
    printf("\n");
}


/*****************/
/** 正则表达式  **/
/*****************/

/**
 * 匹配主函数
 */
int match(const char *regexp, const char *text)
{
    if (regexp[0] == '^')
        return matchhere(regexp+1, text);
    do {
        if (matchhere(regexp, text))
            return 1;
    } while (*text++ != '\0');
    return 0;
}
 
/**
 * 实际匹配函数
 */
int matchhere(const char *regexp, const char *text)
{
    if (regexp[0] == '\0')
        return 1;

    if (regexp[0]=='$' && regexp[1]=='\0')
        return *text == '\0';

    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp+2, text);

    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
        return matchhere(regexp+1, text+1);

    return 0;
}
 
/**
 * 匹配星号函数
 */
int matchstar(int c, const char *regexp, const char *text)
{
    do {
        if (matchhere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return 0;
}

/**
 * 正则表达式测试函数
 */
void testRegex()
{
    printf("Test Regex:\n");
    string regexp = "xa$";
    string text = "bcabcdefgxa";
    int ret = match(regexp.c_str(), text.c_str());
    printf("%d\n", ret);
}


int main()
{
    testLongestPalindrome();
    testRGBSort();
    testMaxSlidingWindow();
    testRegex();
    testPerm();
    testLCS();
    return 0;
}
