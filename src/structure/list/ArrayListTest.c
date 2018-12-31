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

void callback(size_t index, void* data) {
    if (data != NULL) {
        printf("iterate, index: %lu, data: %d\n", index, *(int*)data);
    }
}

int main() {
    ArrayList* list = createArrayList(1, 1.1);
    printf("Hello, I'm list");

    int* node1 = (int*)malloc(sizeof(int));
    int* node2 = (int*)malloc(sizeof(int));

    *node1 = 1;
    *node2 = 2;

    addIntoArrayList(list, node1);
    printf("The capacity is %lu\n", list->capacity);
    addIntoArrayList(list, node2);
    printf("The capacity is %lu\n", list->capacity);

    int* node3 = (int*)malloc(sizeof(int));
    *node3 = 3;

    insertIntoArrayList(list, 0, node3);

    int* node4 = (int*)malloc(sizeof(int));
    *node4 = 4;

    insertIntoArrayList(list, 10, node4);

    int* node5 = malloc(sizeof(int));
    *node5 = 5;

    replaceFromArrayList(list, 5, node5);

    iterateArrayList(list, &callback);

    removeFromArrayList(list, 1);

    size_t index = indexOfArrayList(list, node4);
    size_t lastIndex = lastIndexOfArrayList(list, node4);
    printf("index: %lu \n", index);
    printf("last index: %lu \n", lastIndex);
    for (size_t i = 0; i < list->size; i++) {
        int* data = (int*)list->data[i];
        if (data == NULL) {
            continue;
        }
        printf("index: %lu, data: %d \n", i, *(int*)list->data[i]);
    }

    destroyArrayList(list);

    testAdd();
}

