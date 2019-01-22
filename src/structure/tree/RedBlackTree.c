/*
 * =====================================================================================
 *
 *       Filename:  RedBlackTree.c
 *
 *    Description:  red black tree impl. see
 * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
 *                  also,
 * http://eternallyconfuzzled.com/tuts/datastructures/jsw_tut_rbtree.aspx
 *
 *        Version:  1.0
 *        Created:  01/14/2019 03:12:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../queue/Queue.c"

typedef struct TreeNode {
    void* data;
    bool isRed;  // whether the node is black node
    struct TreeNode* child[2];
} TreeNode;

typedef struct RedBlackTree {
    TreeNode* root;
    int (*compare)(void*, void*);
} RedBlackTree;

bool isRedNode(TreeNode* node) { return node != NULL && !node->isRed; }

/**
 *
 */
TreeNode* singleRotation(TreeNode* root, int dir) {
    // if dir is left child, now the !dir is right child
    TreeNode* otherSide = root->child[!dir];
    root->child[!dir] = otherSide->child[dir];
    otherSide->child[dir] = root;

    otherSide->isRed = false;
    root->isRed = true;
    return otherSide;
}

TreeNode* doubleRotation(TreeNode* root, int dir) {
    root->child[!dir] = singleRotation(root->child[!dir], !dir);
    return singleRotation(root, dir);
}

bool bigger(TreeNode* node, TreeNode* other, RedBlackTree* tree) {
    return tree->compare(node->data, other->data);
}

// return the height of tree, root ==NULL -> 1;
// return 0 -> it's not a red black tree;
int assertBalance(TreeNode* root, RedBlackTree* tree) {
    if (root == NULL) {
        return 1;
    } else {
        TreeNode* left = root->child[0];
        TreeNode* right = root->child[1];
        if (isRedNode(root)) {
            if (isRedNode(left) || isRedNode(right)) {
                printf("red violation");
                return 0;
            }
        }

        int leftHeight = assertBalance(left, tree);
        int rightHeight = assertBalance(right, tree);

        if ((left != NULL && bigger(left, root, tree)) ||
            (right != NULL && bigger(right, root, tree))) {
            printf("Binary tree violation!");
            return 0;
        }

        if (leftHeight != 0 && rightHeight != 0 && leftHeight != rightHeight) {
            printf("black violaton");
            return 0;
        }

        if (leftHeight != 0 && rightHeight != 0) {
            return isRedNode(root) ? leftHeight : leftHeight + 1;
        } else {
            return 0;
        }
    }
}

// always color the node as red
TreeNode* createTreeNode(void* data, bool isRed) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->child[0] = NULL;
    node->child[1] = NULL;
    node->isRed = isRed;
    return node;
}

RedBlackTree* createRedBlackTree(void* data, int (*comparator)(void*, void*)) {
    RedBlackTree* tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    TreeNode* root = createTreeNode(data, false);
    tree->root = root;
    tree->compare = comparator;
    return tree;
}

TreeNode* insertIntoRedBlackTree(RedBlackTree* tree, TreeNode* root,
                                 void* data) {
    if (root == NULL) {
        root = createTreeNode(data, true);
    } else {
        int cmpRes = tree->compare(root->data, data);
        int dir = cmpRes < 0;
        root->child[dir] = insertIntoRedBlackTree(tree, root->child[dir], data);
        // case 1
        if (isRedNode(root->child[!dir])) {
            root->isRed = true;
            root->child[dir]->isRed = false;
            root->child[!dir]->isRed = false;
        } else {
            if (isRedNode(root->child[dir]->child[dir])) {
                root = singleRotation(root, !dir);
            } else if (isRedNode(root->child[dir]->child[!dir])) {
                root = doubleRotation(root, !dir);
            }
        }
    }
    return root;
}

void addIntoRedBlackTree(RedBlackTree* tree, void* data) {
    insertIntoRedBlackTree(tree, tree->root, data);
    tree->root->isRed = false;
}

// breadth-first search
void bfs(RedBlackTree* tree, void (*callback)(void*)) {
    Queue* queue = createQueue();
    enqueue(queue, tree->root);
    TreeNode* node;

    while (!isEmptyQueue(queue)) {
        node = dequeue(queue);
        for (int i = 0; i < 2; i++) {
            if (node->child[i] != NULL) {
                enqueue(queue, node->child[i]);
            }
        }
        void* data = node->data;
        callback(data);
    }
}
