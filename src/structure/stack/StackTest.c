/*
 * =====================================================================================
 *
 *       Filename:  StackTest.c
 *
 *    Description:  Test for Stack.c
 *
 *        Version:  1.0
 *        Created:  01/14/2019 07:04:00 PM
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
#include <stdlib.h>
#include "Stack.c"

int main() {
    Stack* s = createStack();
    int* num1 = (int*)malloc(sizeof(int*));
    *num1 = 1;

    pushIntoStack(s, num1);
    int* data = (int*)popFromStack(s);
    printf("The data is %d \n", *data);
}

