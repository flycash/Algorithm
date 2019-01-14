/*
 * =====================================================================================
 *
 *       Filename:  RedBlackTreeTest.c
 *
 *    Description:  test for RedBlackTree.c
 *
 *        Version:  1.0
 *        Created:  01/14/2019 04:10:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "RedBlackTree.c"

int compare(void* data1, void* data2) {
    int* num1 = (int*)data1;
    int* num2 = (int*)data2;
    return num1 - num2;
}

void callback(void* data) {
    int num = *(int*)data;
    printf("%d ", num);
}

int main() {
    int (*comparator)(void*, void*) = &compare;
    int* rootData = (int*)malloc(sizeof(int*));
    *rootData = 0;
    RedBlackTree* tree = createRedBlackTree(rootData, comparator);

    bfs(tree, &callback);
}
