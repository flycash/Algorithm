/*
 * =====================================================================================
 *
 *       Filename:  ArrayListTest.c
 *
 *    Description:  test array list
 *
 *        Version:  1.0
 *        Created:  2018/12/18 23时26分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8),
 * ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "ArrayList.c"
#include <stdio.h>

void testAdd() {}

int main() {
    ArrayList* list = createArrayList(10, 1.1);
    printf("Hello, I'm list");

    int node1 = 1;
    int node2 = 2;
    addIntoArrayList(list, &node1);
    addIntoArrayList(list, &node2);

    for (size_t i = 0; i < list->size; i++) {
        printf("index: %lu, data: %d", i, *(int*)list->data[i]);
    }

    destroyArrayList(list);

    testAdd();
}

