/*
 * =====================================================================================
 *
 *       Filename:  Stack.c
 *
 *    Description:  the implement of stack. it using the LinkedList as implement
 *
 *        Version:  1.0
 *        Created:  01/14/2019 04:25:24 PM
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

typedef struct Stack {
    LinkedList* list;
} Stack;

Stack* createStack() {
    LinkedList* list = createLinkedList();
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->list = list;
    return s;
}

void pushIntoStack(Stack* stack, void* data) {
    addIntoLinkedList(stack->list, data);
}

void* popFromStack(Stack* stack) {
    return removeTailFromLinkedList(stack->list);
}
