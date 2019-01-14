/*
 * =====================================================================================
 *
 *       Filename:  QueueTest.c
 *
 *    Description:  Test for Queue.c
 *
 *        Version:  1.0
 *        Created:  01/14/2019 07:33:57 PM
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
#include "Queue.c"

int main() {
    Queue* queue = createQueue();

    int* num1 = (int*)malloc(sizeof(int*));
    *num1 = 1;

    enqueue(queue, num1);

    int result = *(int*)dequeue(queue);
    printf("The result is %d", result);
}

