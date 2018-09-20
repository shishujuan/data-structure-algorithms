#include <stdio.h>
#include "bt.h"

void testBTOperation()
{
    BTNode *root = NULL;
    root = bstInsertIter(root, 5);
    root = bstInsert(root, 2);
    root = bstInsertIter(root, 4);
    root = bstInsert(root, 1);
    root = bstInsert(root, 7);
    root = bstInsert(root, 6);

    printf("PreOrder: ");
    preOrder(root);
    printf("\n");
    printf("PreOrderIter: ");
    preOrderIter(root);
    printf("\n");

    printf("InOrder: ");
    inOrder(root);
    printf("\n");
    printf("InOrderIter: ");
    inOrderIter(root);
    printf("\n");

    printf("PostOrder: ");
    postOrder(root);
    printf("\n");
    printf("PostOrderIter: ");
    postOrderIter(root);
    printf("\n");
    printf("PostOrderIterWith2Stack: ");
    postOrderIterWith2Stack(root);
    printf("\n");

    printf("LevelOrder: \n");
    levelOrder(root);
    printf("\n");
    printf("LevelOrderIter: \n");
    levelOrderIter(root);
    printf("\n");

    int key = 8;
    BTNode *node = bstSearch(root, key);
    if (node) {
        printf("Found:%d\n", key);
    } else {
        printf("Not found:%d\n", key);
    }

    BTNode *parent;
    key = 2;
    node = bstSearchIter(root, &parent, key);
    if (node) {
        printf("Found:%d\n", key);
        if (parent) {
            printf("Parent:%d\n", parent->value);
        }
    } else {
        printf("Not found:%d\n", key);
    }

    int delete[] = {2, 5, 7};
    int i;
    for (i = 0; i < 3; i++) {
        printf("Delete %d\n", delete[i]);
        root = bstDelete(root, delete[i]);
        printf("PreOrder: ");
        preOrder(root);
        printf("\n");
    }

    printf("Min:%d, Max:%d\n", bstMin(root)->value, bstMax(root)->value);
    printf("Size:%d, Height:%d\n", size(root), height(root));
}

int main()
{
    testBTOperation();
    return 0;
}
