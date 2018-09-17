#ifndef __ADLIST_H__
#define __ADLIST_H__

#define debug 0

/********************************/
/*代码取自redis 源码的 adlist.c */
/********************************/

// 链表结点
typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *value;
} ListNode;

// 链表
typedef struct List {
    ListNode *head; // 链表头
    ListNode *tail; // 链表尾
    unsigned long len; // 链表长度(结点数)

    void *(*dup)(void *ptr); // 结点复制函数
    void (*free)(void *ptr); // 结点释放函数
    int (*match)(void *ptr, void *key); // 结点匹配函数
} List;

// 链表迭代器
typedef struct ListIter {
    ListNode *next; // 下一个结点
    int direction; // 链表遍历方向
} ListIter;

#define listLength(l) ((l)->len)
#define listHead(l) ((l)->head)
#define listLast(l) ((l)->tail)
#define listPrevNode(n) ((n)->prev)
#define listNextNode(n) ((n)->next)
#define listNodeValue(n) ((n)->value)

#define listSetMatchMethod(l, m) ((l)->match = (m))
#define listSetFreeMethod(l, m) ((l)->free = (m))
#define listSetDupMethod(l, m) ((l)->dup = (m))

List *listCreate(void);
List *listAddNodeHead(List *list, void *value);
List *listAddNodeTail(List *list, void *value);
List *listDup(List *orig);
ListIter *listGetIterator(List *list, int direction);
void listDelNode(List *list, ListNode *node);
void listReleaseIterator(ListIter *iter);

ListNode *listNewNode(void *value);
ListNode *listNext(ListIter *iter);
ListNode *listSearchKey(List *list, void *key);
ListNode *listIndex(List *list, long index);

void listTraverse(List *list, int direction);
void listRelease(List *list);

#define AL_START_HEAD 0 // 从头遍历
#define AL_START_TAIL 1 // 从尾遍历

#endif
