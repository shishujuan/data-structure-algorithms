#include <stdio.h>
#include <stdlib.h>
#include "aslist.h"

/**
 * 创建链表结点
 */
ListNode *listNewNode(int value)
{
    ListNode *node;
    if (!(node = malloc(sizeof(ListNode))))
        return NULL;

    node->value = value;
    node->next = NULL;
    return node;
}

/**
 * 头插法插入结点。
 */
ListNode *listAddNodeHead(ListNode *head, int value)
{
    if (debug) {
        printf("AddNodeHeader: %d\n", value);
    }

    ListNode *node;
    if (!(node = listNewNode(value)))
        return NULL;

    if (head) 
        node->next = head;

    head = node;
    return head;
}

/**
 * 尾插法插入值为value的结点。
 */
ListNode *listAddNodeTail(ListNode *head, int value)
{
    if (debug) {
        printf("AddNodeTail: %d\n", value);
    }

    ListNode *node;
    if (!(node = listNewNode(value)))
        return NULL;

    return listAddNodeTailWithNode(head, node);
}

/**
 * 尾插法插入结点。
 */
ListNode *listAddNodeTailWithNode(ListNode *head, ListNode *node)
{
    if (!head) {
        head = node;
    } else {
        ListNode *current = head;
        while (current->next) {
            current = current->next;
        } 
        current->next = node;
    }
    return head;
}

/**
 * 从链表删除值为value的结点。
 */
ListNode *listDelNode(ListNode *head, int value)
{
    if (debug) {
        printf("DelNode: %d\n", value);
    }

    ListNode *current=head, *prev=NULL;

    while (current) {
        if (current->value == value) {
            if (current == head)
                head = head->next;

            if (prev)
                prev->next = current->next;

            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
    return head;
}

/**
 * 链表遍历。
 */
void listTraverse(ListNode *head)
{
    ListNode *current = head;
    while (current) {
        printf("%d", current->value);
        printf("->");
        current = current->next;
        if (current == head) // 处理首尾循环链表情况
            break;
    }

    printf("NULL\n");
}

/**
 * 使用数组初始化一个链表，共len个元素。
 */
ListNode *listCreate(int a[], int len)
{
    ListNode *head = NULL;
    int i;
    for (i = 0; i < len; i++) {
        if (!(head = listAddNodeTail(head, a[i])))
            return NULL;
    }
    return head;
}

/**
 * 释放链表
 */
void listRelease(ListNode *head)
{
    ListNode *current = head;
    while (current) {
        ListNode *next = current->next;
        free(current);
        current = next;
    }
}

int listLength(ListNode *head)
{
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
