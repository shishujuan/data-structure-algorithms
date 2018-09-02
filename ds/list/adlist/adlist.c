#include <stdlib.h>
#include <stdio.h>
#include "adlist.h"

/**
 * 创建链表
 */
List *listCreate(void)
{
    List *list;

    if ((list = malloc(sizeof(*list))) == NULL)
        return NULL;

    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;

    return list;
}

void listRelease(List *list)
{
    unsigned long len;
    ListNode *current, *next;

    current = list->head;
    len = list->len;
    while(len--) {
        next = listNextNode(current);
        if (list->free)
            list->free(current->value);

        free(current);
        current = next;
    }   

    free(list);
}

/**
 * 新建链表结点
 */
ListNode *listNewNode(void *value)
{
    ListNode *node;
    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;

    node->value = value;
    return node;
}

/**
 * 头插法
 */
List *listAddNodeHead(List *list, void *value)
{
    ListNode *node;

    if ((node = listNewNode(value)) == NULL)
        return NULL;

    // list是空链表
    if (list->len == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    // 非空链表
    } else {
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->len++;

    return list;
}

/**
 * 尾插法
 */
List *listAddNodeTail(List *list, void *value)
{
    ListNode *node;

    if ((node = listNewNode(value)) == NULL)
        return NULL;

    if (list->len == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    } else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }

    list->len++;

    return list;
}

void listDelNode(List *list, ListNode *node)
{
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    if (list->free)
        list->free(node->value);

    free(node);

    list->len--;
}

ListNode *listSearchKey(List *list, void *key)
{
    ListIter *iter = listGetIterator(list, AL_START_HEAD);
    ListNode *node, *found = NULL;

    while ((node = listNext(iter))) {
        if (list->match) {
            if (list->match(node->value, key)) {
                found = node;
                break;
            }
        } else {
            if (key == node->value) {
                found = node;
                break;
            }
        }
    }

    listReleaseIterator(iter);
    return found;
}

ListNode *listIndex(List *list, long index)
{
    ListNode *node;
    if (index < 0) {
        index = (-index) - 1;
        node = list->tail;
        while (index-- && node)
            node = node->prev;
    } else {
        node = list->head;
        while (index-- && node)
            node = node->next;
    }
    return node;
}

ListIter *listGetIterator(List *list, int direction)
{
    ListIter *iter;
    if ((iter = malloc(sizeof(*iter))) == NULL)
        return NULL;

    if (direction == AL_START_HEAD)
        iter->next = list->head;
    else
        iter->next = list->tail;

    iter->direction = direction;
    return iter;
}

void listReleaseIterator(ListIter *iter)
{
    free(iter);
}

ListNode *listNext(ListIter *iter)
{
    ListNode *current = iter->next;
    if (current) {
        if (iter->direction == AL_START_HEAD) {
            iter->next = current->next;
        } else {
            iter->next = current->prev;
        }
    }
    return current;
}

List *listDup(List *orig)
{
    List *copy;
    ListIter *iter;
    ListNode *node;

    if ((copy = listCreate()) == NULL)
        return NULL;

    copy->dup = orig->dup;
    copy->free = orig->free;
    copy->match = orig->match;

    iter = listGetIterator(orig, AL_START_HEAD);
    while((node = listNext(iter)) != NULL) {
        void *value;

        if (copy->dup) {
            value = copy->dup(node->value);
            if (value == NULL) {
                listRelease(copy);
                listReleaseIterator(iter);
                return NULL;
            }   
        } else
            value = node->value;

        if (listAddNodeTail(copy, value) == NULL) {
            listRelease(copy);
            listReleaseIterator(iter);
            return NULL;
        }   
    }   

    listReleaseIterator(iter);
    return copy;
}

void listTraverse(List *list, int direction)
{
    ListIter *iter = listGetIterator(list, direction);
    ListNode *current;
    while ((current = listNext(iter))) {
        printf("%s -> ", current->value);
    }
    printf("NULL\n");
}
