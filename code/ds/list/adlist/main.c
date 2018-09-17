#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adlist.h"

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

void freeString(void *ptr)
{
    free(ptr);
}

int matchString(void *s1, void *s2)
{
    if (strcmp(s1, s2) == 0)
        return 1;
    else
        return 0;
}

char *newString(char *s)
{
    int len = strlen(s);
    char *news = (char *)malloc(sizeof(len+1));
    strcpy(news, s);
    return news;
}

void *dupString(void *s1)
{
   void *sdup = newString(s1); 
   return sdup;
}


List *createTestListFromArray(char *a[], int len)
{
    List *list = listCreate();
    listSetFreeMethod(list, freeString);
    listSetDupMethod(list, dupString);
    listSetMatchMethod(list, matchString);
    int i;
    for (i = 0; i < len; i++) {
        listAddNodeTail(list, (void *)a[i]);
    }
    return list;
}

int main()
{
    char *a[] = {
        newString("aa"),
        newString("bb"),
        newString("cc")
    };
    List *list = createTestListFromArray(a, ALEN(a));
    listTraverse(list, AL_START_HEAD);
    listTraverse(list, AL_START_TAIL);

    ListNode *node = listSearchKey(list, "aa");
    if (node) {
        printf("Found Node:%s\n", node->value);
    } else {
        printf("Not Found");
    }

    node = listIndex(list, 1);
    if (node) {
        printf("Found index 1 Node:%s\n", node->value);
    } else {
        printf("Not found\n");
    }

    List *listCopy = listDup(list);

    listDelNode(list, node);
    printf("Del Node in index 1\n");

    listTraverse(list, AL_START_HEAD);

    printf("Traverse dup list\n");
    listTraverse(listCopy, AL_START_HEAD);
    listTraverse(listCopy, AL_START_TAIL);

    listRelease(list);
    return 0;
}
