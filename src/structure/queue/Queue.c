/*
 * =====================================================================================
 *
 *       Filename:  Queue.c
 *
 *    Description:  the implement of queue
 *
 *        Version:  1.0
 *        Created:  01/14/2019 07:25:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "../list/LinkedList.c"

typedef struct Queue {
    LinkedList* list;
} Queue;

Queue* createQueue() {
    LinkedList* list = createLinkedList();
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->list = list;
    return queue;
}

void enqueue(Queue* queue, void* data) { addIntoLinkedList(queue->list, data); }

void* dequeue(Queue* queue) { return removeHeadFromLinkedList(queue->list); }

bool isEmptyQueue(Queue* queue) { return queue->list->size == 0; }
