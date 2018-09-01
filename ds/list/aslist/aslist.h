#ifndef __ASLIST_H__
#define __ASLIST_H__

#define debug 0

typedef struct ListNode {
    struct ListNode *next;
    int value;
} ListNode;

ListNode *listAddNodeHead(ListNode *head, int value);
ListNode *listAddNodeTail(ListNode *head, int value);
ListNode *listDelNode(ListNode *head, int value);
ListNode *listCreate(int a[], int len);
ListNode *listNewNode(int value);
ListNode *listAddNodeTailWithNode(ListNode *head, ListNode *node);
int listLength(ListNode *head);

void listTraverse(ListNode *head);
void listRelease(ListNode *head);

#endif
