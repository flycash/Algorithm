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
#include <stdlib.h>
#include "../queue/Queue.c"

typedef struct TreeNode {
    void* data;
    bool isBlack;  // whether the node is black node
    struct TreeNode* child[2];
} TreeNode;

typedef struct RedBlackTree {
    TreeNode* root;
    int (*compare)(void*, void*);
} RedBlackTree;

bool isRedNode(TreeNode* node) { return node != NULL && !node.isBlack; }

TreeNode* createTreeNode(void* data, bool isBlack) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->child[0] = NULL;
    node->child[1] = NULL;
    return node;
}

RedBlackTree* createRedBlackTree(void* data, int (*comparator)(void*, void*)) {
    RedBlackTree* tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    TreeNode* root = createTreeNode(data, true);
    tree->root = root;
    tree->compare = comparator;
    return tree;
}

void addIntoRedBlackTree(RedBlackTree* tree, void* data) {
    // TODO
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
