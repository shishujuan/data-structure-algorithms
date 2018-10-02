#include <stdio.h>
#include <util.h>
#include "knap.h"

void testKnap()
{
    int w[] = {3, 4, 5};
    int v[] = {4, 5, 6};
    int N = ALEN(w);
    int C = 10;
    int max = knap01(N, C, w, v);
    printf("KNap01 max: %d\n", max);

    int maxComplete = knapComplete(N, C, w, v);
    printf("KNapComplete max: %d\n", maxComplete);

    int maxComplete01 = knapCompleteLike01(N, C, w, v);
    printf("KNapCompleteLike01 max: %d\n", maxComplete01);
}

int main()
{
    testKnap();
    return 0;
}
