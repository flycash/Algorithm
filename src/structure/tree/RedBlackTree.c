/*
 * =====================================================================================
 *
 *       Filename:  RedBlackTree.c
 *
 *    Description:  red black tree impl
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
#include <stdlib.h>
#include "../list/LinkedList.c"

typedef struct TreeNode {
    void* data;
    bool isBlack;  // whether the node is black node
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct RedBlackTree {
    TreeNode* root;
    int (*compare)(void*, void*);
} RedBlackTree;

TreeNode* createTreeNode(void* data, bool isBlack) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->isBlack = isBlack;
    node->left = NULL;
    node->right = NULL;
    return node;
}

RedBlackTree* createRedBlackTree(void* data, int (*comparator)(void*, void*)) {
    RedBlackTree* tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    TreeNode* root = createTreeNode(data, true);
    tree->root = root;
    tree->compare = comparator;
    return tree;
}

// breadth-first search
void bfs(RedBlackTree* tree) {}
