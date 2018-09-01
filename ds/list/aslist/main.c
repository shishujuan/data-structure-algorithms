#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "aslist.h"

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

/**
 * 链表增减结点测试
 */
void testListModify()
{
    printf("\nTestListModify\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    printf("Origin List:\n");
    ListNode *head = listCreate(a, ALEN(a));
    listTraverse(head);

    printf("Del Node 3\n");
    head = listDelNode(head, 3);
    listTraverse(head);
    
    printf("Del Node 1\n");
    head = listDelNode(head, 1);
    listTraverse(head);
    
    head = listDelNode(head, 6);
    head = listAddNodeTail(head, 7);
    printf("Del Node 6, Add Tail 7\n");
    listTraverse(head);
    
    head = listDelNode(head, 4);
    head = listAddNodeTail(head, 8);
    head = listAddNodeHead(head, 9);
    printf("Del Node 4, Add Tail 8, Add Head 9\n");
    listTraverse(head);
}


/**************/
/** 链表逆序 **/
/**************/

/**
 * 链表逆序，非递归实现。
 */
ListNode *listReverse(ListNode *head)
{
    ListNode *newHead = NULL, *current = head;
    while (current) {
        ListNode *next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }

    return newHead;
}

/**
 * 链表逆序，递归实现。
 */
ListNode *listReverseRecursive(ListNode *head)
{
    if (!head || !head->next) {
        return head;
    }

    ListNode *reversedHead = listReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversedHead;
}

/**
 * 链表逆序测试函数
 */
void testListReverse(void)
{
    printf("\nTestListReverse\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    ListNode *initList = listCreate(a, ALEN(a));
    listTraverse(initList);
    ListNode *reversedList = listReverse(initList);
    listTraverse(reversedList);
    
    ListNode *reversedListRecursive = listReverseRecursive(reversedList);
    listTraverse(reversedListRecursive);
    
    listRelease(initList);
}


/**************/
/** 链表复制 **/
/**************/

/**
 * 链表复制-非递归
 */
ListNode *listCopy(ListNode *head) 
{
    ListNode *current = head, *newHead = NULL, *newTail = NULL; 
    while (current) {
        ListNode *node = listNewNode(current->value);
        if (!newHead) {
            newHead = newTail = node;
        } else {
            newTail->next = node;
            newTail = node;
        }
        current = current->next;
    }
    return newHead;
}

/**
 * 链表复制-递归
 */
ListNode *listCopyRecursive(ListNode *head)
{
    if (!head) 
        return NULL;

    ListNode *newHead = listNewNode(head->value);
    newHead->next = listCopyRecursive(head->next);
    return newHead;
}

/**
 * 链表复制测试函数
 */
void testListCopy(void)
{
    printf("\nTestListCopy\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    ListNode *initList = listCreate(a, ALEN(a));
    listTraverse(initList);

    ListNode *copyList = listCopyRecursive(initList);
    listTraverse(copyList);

    ListNode *reversedList = listReverse(copyList);
    listTraverse(reversedList);

    listTraverse(initList);
}


/**************/
/** 链表合并 **/
/**************/

/**
 * 链表合并-非递归
 */
ListNode *listMerge(ListNode *list1, ListNode *list2)
{
    ListNode dummy; // 使用空结点保存合并链表
    ListNode *tail = &dummy;

    if (!list1)
        return list2;

    if (!list2)
        return list1;

    while (list1 && list2) {
        if (list1->value <= list2->value) {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }

    if (list1) {
        tail->next = list1;
    } else if (list2) {
        tail->next = list2;
    }

    return dummy.next;
}

/**
 * 链表合并-递归
 */
ListNode *listMergeRecursive(ListNode *list1, ListNode *list2)
{
    ListNode *result = NULL;

    if (!list1)
        return list2;

    if (!list2)
        return list1;

    if (list1->value <= list2->value) {
        result = list1;
        result->next = listMergeRecursive(list1->next, list2);
    } else {
        result = list2;
        result->next = listMergeRecursive(list1, list2->next);
    }

    return result;
}

/**
 * 链表合并测试函数
 */
void testListMerge()
{
    printf("\nTestListMerge\n");
    int a1[] = {1, 3, 5};
    int a2[] = {2, 4, 6, 7, 8};

    ListNode *list1 = listCreate(a1, ALEN(a1));
    ListNode *list2 = listCreate(a2, ALEN(a2));
    ListNode *listMerged = listMerge(list1, list2);
    listTraverse(listMerged);

    list1 = listCreate(a1, ALEN(a1));
    list2 = listCreate(a2, ALEN(a2));
    listMerged = listMergeRecursive(list2, list1);
    listTraverse(listMerged);
}


/**************/
/** 链表相交 **/
/**************/

/**
 * 链表相交判断，如果相交返回相交的结点，否则返回NULL。
 */
ListNode *listIntersect(ListNode *list1, ListNode *list2)
{
    int len1 = listLength(list1);
    int len2 = listLength(list2);
    int delta = abs(len1 - len2);

    ListNode *longList = list1, *shortList = list2;

    if (len1 < len2) {
        longList = list2;
        shortList = list1;
    }

    int i;
    for (i = 0; i < delta; i++) {
        longList = longList->next;
    }

    while (longList && shortList) {
        if (longList == shortList)
            return longList;

        longList = longList->next;
        shortList = shortList->next;
    }

    return NULL;
}

/**
 * 链表相交测试函数
 */
void testListIntersect()
{
    printf("\nTestListIntersect\n");
    int a1[] = {1, 3, 5};
    int a2[] = {2, 4, 6, 7};

    ListNode *list1 = listCreate(a1, ALEN(a1));
    ListNode *list2 = listCreate(a2, ALEN(a2));

    ListNode *sameNode = listIntersect(list1, list2);
    assert(sameNode == NULL);

    listTraverse(list1);
    listTraverse(list2);

    ListNode *sameNode1 = listNewNode(8);
    ListNode *sameNode2 = listNewNode(9);

    list1 = listAddNodeTailWithNode(list1, sameNode1);
    list1 = listAddNodeTailWithNode(list1, sameNode2);
    list2 = listAddNodeTailWithNode(list2, sameNode1);
    listTraverse(list1);
    listTraverse(list2);

    sameNode = listIntersect(list1, list2);
    assert(sameNode == sameNode1);
}


/******************/
/** 链表模拟加法 **/
/******************/

/**
 * 链表模拟加法-非递归解法
 */
ListNode *listEnumarateAdd(ListNode *list1, ListNode *list2)
{
    int carry = 0;
    ListNode *result = NULL;

    while (list1 || list2 || carry) {
        int value = carry;
        if (list1) {
            value += list1->value;
            list1 = list1->next;
        }

        if (list2) {
            value += list2->value;
            list2 = list2->next;
        }

        result = listAddNodeTail(result, value % 10);
        carry = ( value >= 10 ? 1: 0);
    }

    return result;
}

/**
 * 链表模拟加法-递归解法
 */
ListNode *listEnumarateAddRecursive(ListNode *list1, ListNode *list2, int carry)
{
    if (!list1 && !list2 && carry==0)
        return NULL;

    int value = carry;
    if (list1)
        value += list1->value;

    if (list2)
        value += list2->value;

    ListNode *next1 = list1 ? list1->next : NULL;
    ListNode *next2 = list2 ? list2->next : NULL;
    ListNode *more = listEnumarateAddRecursive(next1, next2, (value >= 10 ? 1 : 0));
    ListNode *result = listNewNode(carry);
    result->value = value % 10;
    result->next = more;

    return result;
}

/**
 * 链表模拟加法测试代码
 */
void testListEnumerateAdd()
{
    printf("\nTestListEnumerateAdd\n");
    int a1[] = {1, 3, 5};
    int a2[] = {2, 4, 6, 7};

    ListNode *list1 = listCreate(a1, ALEN(a1));
    ListNode *list2 = listCreate(a2, ALEN(a2));
    ListNode *result = listEnumarateAdd(list1, list2);
    listTraverse(result);

    int a3[] = {1, 3, 5};
    int a4[] = {2, 8, 6, 7};
    ListNode *list3 = listCreate(a3, ALEN(a3));
    ListNode *list4 = listCreate(a4, ALEN(a4));
    result = listEnumarateAddRecursive(list3, list4, 0);
    listTraverse(result);
}


/******************/
/*** 链表环判断 ***/
/******************/
/**
 * 检测链表是否有环-Flod判圈算法
 * 若存在环，返回相遇结点，否则返回NULL
 */
ListNode *listDetectLoop(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

/**
 * 查找链表中环入口
 */
ListNode *findLoopNode(ListNode *head)
{
    ListNode *meetNode = listDetectLoop(head);
    if (!meetNode)
        return NULL;

    ListNode *headNode = head;
    while (meetNode != headNode) {
        meetNode = meetNode->next;
        headNode = headNode->next;
    }
    return meetNode;
}

/**
 * 检测链表是否有环测试函数
 */
void testListDetectLoop()
{
    printf("\nTestListDetectLoop\n");
    int a[] = {1, 2, 3, 4};
    ListNode *head = listCreate(a, ALEN(a));
    ListNode *ret = listDetectLoop(head);
    if (ret) {
        printf("Found Loop\n");
    } else {
        printf("No Loop\n");
    }

    // 构造一个环
    head->next->next->next = head;
    ListNode *loopNode = findLoopNode(head);
    if (loopNode) {
        printf("Found Loop, start at:%d\n", loopNode->value);
    } else {
        printf("No Loop\n");
    }
}


/**********************/
/*有序循环链表插入结点*/
/**********************/

/**
 * 简化版-有序无循环链表插入结点
 */
ListNode *sortedListAddNode(ListNode *head, int value)
{
    ListNode *node = listNewNode(value);
    if (!head || head->value >= value) { //情况1
        node->next = head;
        head = node;
    } else {  //情况2
        ListNode *current = head;
        while (current->next != NULL && current->next->value < value)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }
    return head;
}

/**
 * 简化版-有序无循环链表插入结点(两种情况一起处理)
 */
void sortedListAddNodeUnify(ListNode **head, int value)
{
    ListNode *node = listNewNode(value);
    ListNode **current = head;
    while ((*current) && (*current)->value < value) {
        current = &((*current)->next);
    }
    node->next = *current;
    *current = node;
}

/**
 * 有序循环链表插入结点
 */
ListNode *sortedLoopListAddNode(ListNode *head, int value)
{
    ListNode *node = listNewNode(value);
    ListNode *current = head, *prev = NULL;
    do {
        prev = current;
        current = current->next;
        if (value >= prev->value && value <= current->value)
            break;
    } while (current != head);

    prev->next = node;
    node->next = current;

    if (current == head && value < current->value) // 判断是否要设置链表头
        head = node;

    return head;
}

/**
* 有序循环链表插入结点测试函数
*/
void testSortedAddNode()
{
    printf("\nTestSortedAddNode\n");
    int a[] = {2, 4, 5};
    ListNode *head = listCreate(a, ALEN(a));
    listTraverse(head);

    // 添加到头部
    ListNode *newHead = sortedListAddNode(head, 1);
    listTraverse(newHead);

    // 添加到链表中间
    sortedListAddNodeUnify(&newHead, 3);
    listTraverse(newHead);

    // 添加到链表尾部
    sortedListAddNodeUnify(&newHead, 6);
    listTraverse(newHead);

    head = listCreate(a, ALEN(a));
    head->next->next->next = head; // 构造循环
    listTraverse(head);
    head = sortedLoopListAddNode(head, 2); // 插入相等的值测试
    listTraverse(head);
    head = sortedLoopListAddNode(head, 1);
    listTraverse(head);
    head = sortedLoopListAddNode(head, 3);
    listTraverse(head);
    head = sortedLoopListAddNode(head, 6);
    listTraverse(head);
    
}


/*******************/
/*链表倒数第K个结点*/
/*******************/

/**
* 链表倒数第K个结点-遍历两次算法
*/
ListNode *getLastKthNodeTwice(ListNode *head, int k)
{
    int len = listLength(head);     
    if (k > len)
        return NULL;

    ListNode *current = head; 
    int i;
    for (i = 0; i < len-k; i++)  //遍历链表，找出第N-K+1个结点
        current = current->next;

    return current;
}

/**
* 链表倒数第K个结点-遍历一次算法
*/
ListNode *getLastKthNodeOnce(ListNode *head, int k)
{
    ListNode *p1, *p2;
    p1 = p2 = head;

    for(; k > 0; k--) {
        if (!p2) // 链表长度不够K
            return NULL;
        p2 = p2->next;
    }

    while (p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

/**
* 链表倒数第K个结点测试函数
*/
void testGetLastKthNode()
{
    printf("\nTestGetLastKthNode\n");
    int a[] = {1, 2, 3, 4};
    ListNode *head = listCreate(a, ALEN(a));

    int k = 3;
    ListNode *node = getLastKthNodeTwice(head, k);
    if (node) {
        printf("Last Kth Node(Twice): %d\n", node->value);
    } else {
        printf("K > List LEN\n");
    }

    node = getLastKthNodeOnce(head, k);
    if (node) {
        printf("Last Kth Node(Once): %d\n", node->value);
    } else {
        printf("K > List LEN\n");
    }
}

int main(void) 
{
    testListModify();
    testListReverse();
    testListCopy();
    testListMerge();
    testListIntersect();
    testListEnumerateAdd();
    testListDetectLoop();
    testGetLastKthNode();
    testSortedAddNode();
    return 0;
}
