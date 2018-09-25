#ifndef __BT_QUIZ_H
#define __BT_QUIZ_H

#include <stdio.h>
#include <aslist.h>
#include "bt.h"

int isBSTError(BTNode *root);
int isBSTUnefficient(BTNode *root);
int isBSTEfficient(BTNode *root, BTNode *left, BTNode *right);
int isBSTInOrder(BTNode *root, BTNode *prev);

int isCompleteBTLevelOrder(BTNode *root);
int isCompleteBTIndexMethod(BTNode *root, int index, int nodeCount);

int isBalanceBTTop2Down(BTNode *root);
int isBalanceBTDown2Top(BTNode *root, int *height);

int isOmorphism(BTNode *t1, BTNode *t2);

int findBTRootIndex(int inorder[], int n, int rootVal);
BTNode *buildBTFromPreInOrder(int preorder[], int inorder[], int n, int offset, int count);
BTNode *buildBTFromInPostOrder(int postorder[], int inorder[], int n, int offset, int count);

void bstSave(BTNode *root, FILE *fp);
BTNode *bstRestore(FILE *fp);

void btSave(BTNode *root, FILE *fp);
BTNode *btRestore(BTNode *root, FILE *fp);

BTNode *bstLCA(BTNode *root, BTNode *p, BTNode *q);
BTNode *btLCATop2Down(BTNode *root, BTNode *p, BTNode *q);
BTNode *btLCADown2Top(BTNode *root, BTNode *p, BTNode *q);

BTNode *largestSubBSTTop2Down(BTNode *root, int *bstSize);
BTNode *largestSubBSTDown2Top(BTNode *root, int *bstSize);
int findLargestSubBST(BTNode *root, int *min, int *max, int *maxNodes, BTNode **largestSubBST);

int distanceOf2BTNodes(BTNode *root, BTNode *p, BTNode *q);
int btDistanceFromRoot(BTNode *root, BTNode *node, int level);

int distanceOf2BSTNodes(BTNode *root, BTNode *p, BTNode *q);
int bstDistanceFromRoot(BTNode *root, BTNode *node);

int btMaxDistance(BTNode *root, int *maxDepth);

int btMaxWidthLevelOrder(BTNode *root);
int btLevelWidth(BTNode *root, int level);

int btMaxWidthPreOrder(BTNode *root);
void btLevelWidthCount(BTNode *root, int level, int count[]);

BTNode *sortedArray2BST(int a[], int start, int end);
BTNode *sortedList2BST(ListNode **pList, int start, int end);

void bt2DoublyList(BTNode *root, BTNode **pPrev, BTNode **pHead);

#endif
