#include <stdio.h>
#include <util.h>
#include "bt.h"
#include "quiz.h"

/**
 * 创建测试的BST
 */
BTNode *createTestBST()
{
    BTNode *root = NULL;
    root = bstInsertIter(root, 5);
    root = bstInsert(root, 2);
    root = bstInsertIter(root, 4);
    root = bstInsert(root, 1);
    root = bstInsert(root, 7);
    root = bstInsert(root, 6);
    return root;
}

/**
 * 创建测试的二叉树，但不是二叉搜索树
 */
BTNode *createTestBT()
{
    BTNode *root = btNewNode(10);
    root->left = btNewNode(5);
    root->right = btNewNode(15);
    root->right->left = btNewNode(6);
    root->right->right = btNewNode(20);
    return root;
}

/**
 * 创建测试用的完全二叉树
 */
BTNode *createTestCompleteBT()
{
    BTNode *root = btNewNode(10);
    root->left = btNewNode(5);
    root->right = btNewNode(11);
    root->left->left = btNewNode(2);
    root->left->right = btNewNode(6);
    return root;
}

void testBTOperation()
{
    BTNode *root = createTestBST();
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
    printf("Size:%d, Height:%d\n", btSize(root), btHeight(root));
}

void testIsBST()
{
    BTNode *bt = createTestBT();
    printf("\nBinary Tree(but not BST):\n");
    levelOrder(bt);
    printf("\n");
    printf("isBSTError check:%d\n", isBSTError(bt));
    printf("isBSTUnefficient check:%d\n", isBSTUnefficient(bt));
    printf("isBSTEfficient check:%d\n", isBSTEfficient(bt, NULL, NULL));
    printf("isBSTInOrder check:%d\n", isBSTInOrder(bt, NULL));

    BTNode *bst = createTestBST();
    printf("\nBinary Search Tree:\n");
    levelOrder(bst);
    printf("\n");
    printf("isBSTError check:%d\n", isBSTError(bst));
    printf("isBSTUnefficient check:%d\n", isBSTUnefficient(bst));
    printf("isBSTEfficient check:%d\n", isBSTEfficient(bst, NULL, NULL));
    printf("isBSTInOrder check:%d\n", isBSTInOrder(bst, NULL));
}

void testIsCompleteBT()
{
    BTNode *bt = createTestBT();
    printf("\nBinary Tree: \n");
    levelOrder(bt);
    printf("Is Complete BT Level Order Method: %d\n", isCompleteBTLevelOrder(bt));
    printf("Is Complete BT Index Method: %d\n", isCompleteBTIndexMethod(bt, 0, btSize(bt)));
    BTNode *cbt = createTestCompleteBT();
    printf("\nBinary Tree: \n");
    levelOrder(cbt);
    printf("Is Complete BT Level Order Method: %d\n", isCompleteBTLevelOrder(cbt));
    printf("Is Complete BT Index Method: %d\n", isCompleteBTIndexMethod(cbt, 0, btSize(cbt)));
}

void testIsBalanceBT()
{
    printf("\nTest Balanced Binary Tree: \n");
    BTNode *bt = createTestBT();
    levelOrder(bt);
    printf("Is balance: %d\n", isBalanceBTTop2Down(bt));
    bt->right->right->right = btNewNode(18); // make it not balanced
    levelOrder(bt);
    int height;
    printf("Is balance: %d\n", isBalanceBTDown2Top(bt, &height));
}

void testIsOmorphism()
{
    BTNode *t1 = createTestBT();
    BTNode *t2 = createTestBST();
    BTNode *t3 = createTestBT();
    printf("IsOmorphism:%d\n", isOmorphism(t1, t3));
    printf("IsOmorphism:%d\n", isOmorphism(t1, t2));
}

void testBuildBT()
{
    printf("\nBuildBT from pre and in order\n");
    int preorder[] = {7, 10, 4, 3, 1, 2, 8, 11};
    int inorder[] = {4, 10, 3, 1, 7, 11, 8, 2};
    int postorder[] = {4, 1, 3, 10, 11, 8, 2, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    BTNode *root = buildBTFromPreInOrder(preorder, inorder, n, 0, n);
    printf("Preorder:\n");
    preOrder(root);
    printf("\n");
    printf("Inorder:\n");
    inOrder(root);
    printf("\n");
    printf("Postorder:\n");
    postOrder(root);
    printf("\n");

    printf("\nBuildBT from post and in order\n");
    root = buildBTFromInPostOrder(postorder, inorder, n, 0, n);
    printf("Preorder:\n");
    preOrder(root);
    printf("\n");
    printf("Inorder:\n");
    inOrder(root);
    printf("\n");
    printf("Postorder:\n");
    postOrder(root);
    printf("\n");
}

void testSaveRestoreBST()
{
    BTNode *bst = createTestBST();
    printf("\nTest Save/Restore BST\n");
    preOrder(bst);
    printf("\n");

    FILE *fbst = fopen("/tmp/bst.data", "w+");
    if (!fbst) {
        printf("File permission error\n");
        return;
    }
    bstSave(bst, fbst);
    fclose(fbst);

    fbst = fopen("/tmp/bst.data", "r");
    BTNode *bstFile = bstRestore(fbst);
    preOrder(bst);
    printf("\n");
    fclose(fbst);
}

void testSaveRestoreBT()
{
    BTNode *bt = createTestBT();
    printf("\nTest Save/Restore BT\n");
    preOrder(bt);
    printf("\n");
    FILE *fbt = fopen("/tmp/bt.data", "w+");
    btSave(bt, fbt);
    fclose(fbt);

    fbt = fopen("/tmp/bt.data", "r");
    BTNode *btFile = btRestore(NULL, fbt);
    preOrder(btFile);
    printf("\n");
    fclose(fbt);
}

void testLCABST()
{
    BTNode *bst = createTestBST();
    BTNode *p = bst->left->right; // node 4
    BTNode *q = bst->right; // node 7
    BTNode *lca = bstLCA(bst, p, q);
    printf("\nTest BST LCA, p:%d, q:%d, lca:%d\n", p->value, q->value, lca->value);

    q = bst->left; // node 2
    lca = bstLCA(bst, p, q);
    printf("Test BST LCA, p:%d, q:%d, lca:%d\n", p->value, q->value, lca->value);
}

void testLCABT()
{
    BTNode *bt = createTestBT();
    BTNode *p = bt->left; // node 5
    BTNode *q = bt->right; // node 10
    BTNode *lca = btLCATop2Down(bt, p, q);
    BTNode *lca2 = btLCADown2Top(bt, p, q);
    printf("\nTest BT LCA Top2Down, p:%d, q:%d, lca:%d\n", p->value, q->value, lca->value);
    printf("Test BT LCA Down2Top, p:%d, q:%d, lca:%d\n", p->value, q->value, lca2->value);

    p = bt->right->left; // node 6
    lca = btLCATop2Down(bt, p, q);
    lca2 = btLCADown2Top(bt, p, q);
    printf("Test BT LCA Top2Down, p:%d, q:%d, lca:%d\n", p->value, q->value, lca->value);
    printf("Test BT LCA Down2Top, p:%d, q:%d, lca:%d\n", p->value, q->value, lca2->value);
}

void testLargestSubBST()
{
    BTNode *bst = createTestBST();
    int bstSize;
    BTNode *subBST = largestSubBSTTop2Down(bst, &bstSize);
    printf("\nTest Max Sub BST, btSize:%d, root:%d\n", bstSize, subBST->value);
    subBST = largestSubBSTDown2Top(bst, &bstSize);
    printf("Test Max Sub BST, btSize:%d, root:%d\n", bstSize, subBST->value);

    BTNode *bt = createTestBT();
    subBST = largestSubBSTTop2Down(bt, &bstSize);
    printf("Test Max Sub BST, btSize:%d, root:%d\n", bstSize, subBST->value);
    subBST = largestSubBSTDown2Top(bt, &bstSize);
    printf("Test Max Sub BST, btSize:%d, root:%d\n", bstSize, subBST->value);
    printf("\n");

}

void testDistanceOf2BTNodes()
{
 	BTNode *root = btNewNode(1); 
    root->left = btNewNode(2); 
    root->right = btNewNode(3); 
    root->left->left = btNewNode(4); 
    root->left->right = btNewNode(5); 
    root->right->left = btNewNode(6); 
    root->right->right = btNewNode(7); 
    root->right->left->right = btNewNode(8); 
    printf("Dist(4, 5) = %d\n", distanceOf2BTNodes(root, root->left->left, root->left->right)); 
    printf("Dist(4, 6) = %d\n", distanceOf2BTNodes(root, root->left->left, root->right->left)); 
    printf("Dist(3, 4) = %d\n", distanceOf2BTNodes(root, root->right, root->left->left)); 
    printf("Dist(2, 4) = %d\n", distanceOf2BTNodes(root, root->left, root->left->left)); 
    printf("Dist(8, 5) = %d\n", distanceOf2BTNodes(root, root->right->left->right, root->left->right)); 
}

void testDistanceOf2BSTNodes()
{
    BTNode *root = createTestBST();
    BTNode *p = root->left->left; // 1
    BTNode *q = root->right;      // 7
    printf("Distance(1, 7) = %d\n", distanceOf2BSTNodes(root, p, q));
}

void testBTMaxDistance()
{
    printf("\nTest btMaxDistance:\n");
    int maxDepth;
    BTNode *root = btNewNode(10);
    root->left = btNewNode(5);
    root->left->left = btNewNode(1);
    root->left->right = btNewNode(8);
    root->right = btNewNode(15);
    root->right->right = btNewNode(7);
    int maxDistance = btMaxDistance(root, &maxDepth);
    levelOrder(root);
    printf("MaxDistance:%d\n", maxDistance);

    root = btNewNode(10);
    root->left = btNewNode(5);
    root->left->left = btNewNode(1);
    root->left->right = btNewNode(8);
    root->left->left->left = btNewNode(2);
    root->left->right->right = btNewNode(3);
    maxDistance = btMaxDistance(root, &maxDepth);
    levelOrder(root);
    printf("MaxDistance:%d\n", maxDistance);
}

void testBTMaxWidth()
{
 	BTNode *root = btNewNode(1); 
    root->left = btNewNode(2); 
    root->right = btNewNode(3); 
    root->left->left = btNewNode(4); 
    root->left->right = btNewNode(5); 
    root->right->left = btNewNode(6); 
    root->right->right = btNewNode(7); 
    printf("\nTest MaxWidth tree:\n");
    levelOrder(root);
    printf("MaxWidth Levelorder:%d\n", btMaxWidthLevelOrder(root));
    printf("MaxWidth Preorder:%d\n", btMaxWidthPreOrder(root));
}

void testSortedArray2BST()
{
    printf("\nTest SortedArray2BST:\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = ALEN(a);
    printIntArray(a, n);
    BTNode *root = sortedArray2BST(a, 0, n-1);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
}

void testSortedList2BST()
{
    printf("\nTest SortedList2BST:\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = ALEN(a);
    ListNode *list = listCreate(a, n);
    int len = listLength(list);
    listTraverse(list);
    BTNode *root = sortedList2BST(&list, 0, len-1);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
}

void testBT2DoublyList()
{
    printf("\nTest BT2DoublyList:\n");
    BTNode *root = createTestBST();
    inOrder(root);
    printf("\n");
    BTNode *prev = NULL, *head = NULL;
    bt2DoublyList(root, &prev, &head);
    BTNode *current = head;

    while (current) {
        printf("%d ", current->value);
        current = current->right;
        if (current == head)
            break;
    }
    printf("\n");
}

int main()
{
    testBTOperation();
    testIsBST();
    testIsCompleteBT();
    testIsBalanceBT();
    testIsOmorphism();
    testBuildBT();
    testSaveRestoreBST();
    testSaveRestoreBT();
    testLCABST();
    testLCABT();
    testLargestSubBST();
    testDistanceOf2BTNodes();
    testDistanceOf2BSTNodes();
    testBTMaxDistance();
    testBTMaxWidth();
    testSortedArray2BST();
    testSortedList2BST();
    testBT2DoublyList();
    return 0;
}
