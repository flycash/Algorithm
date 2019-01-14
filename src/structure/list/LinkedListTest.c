/*
 * =====================================================================================
 *
 *       Filename:  LinkedListTest.c
 *
 *    Description:  the test for LinkedList.c
 *
 *        Version:  1.0
 *        Created:  01/02/19 17:12:07
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
#include "LinkedList.c"

void printNode(size_t index, void* data) {
    if (data != NULL) {
        printf("index: %lu, data: %d \n", index, *(int*)data);
    }
}

int main() {
    LinkedList* list = createLinkedList();
    int* node1 = (int*)malloc(sizeof(int));
    *node1 = 1;
    int* node2 = (int*)malloc(sizeof(int));
    *node2 = 2;
    addIntoLinkedList(list, node1);
    addIntoLinkedList(list, node2);

    int* node3 = (int*)malloc(sizeof(int));
    *node3 = 3;
    insertIntoLinkedList(list, 0, node3);

    // removeFromLinkedList(list, node2);

    removeFromLinkedListByIndex(list, 1);

    iterateLinkedList(list, &printNode);

    printf("~~~~~~~~\n");
    removeHeadFromLinkedList(list);

    removeTailFromLinkedList(list);

    iterateLinkedList(list, &printNode);
}

