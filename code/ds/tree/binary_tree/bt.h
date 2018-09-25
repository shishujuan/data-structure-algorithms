#ifndef __BST_H
#define __BST_H

typedef struct BTNode {
    int value;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

BTNode *btNewNode(int value);
BTNode *bstInsert(BTNode *root, int value);
BTNode *bstInsertIter(BTNode *root, int value);
BTNode *bstDelete(BTNode *root, int value);
BTNode *bstSearch(BTNode *root, int value);
BTNode *bstSearchIter(BTNode *root, BTNode **parent, int value);
BTNode *bstMin(BTNode *root);
BTNode *bstMax(BTNode *root);

int btSize(BTNode *root);
int btHeight(BTNode *root);
int btExist(BTNode *root, BTNode *node);

void preOrder(BTNode *root);
void inOrder(BTNode *root);
void postOrder(BTNode *root);
void levelOrder(BTNode *root);
void levelOrderInLevel(BTNode *root, int level);

void preOrderIter(BTNode *root);
void inOrderIter(BTNode *root);
void postOrderIter(BTNode *root);
void postOrderIterWith2Stack(BTNode *root);
void levelOrderIter(BTNode *root);

#endif
