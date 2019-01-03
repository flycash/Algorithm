/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumberTest.c
 *
 *    Description:  the test for add two number
 *
 *        Version:  1.0
 *        Created:  01/03/19 23:03:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "AddTwoNumber.c"
#include <stdio.h>

struct ListNode* createNode(int array[], int length) {
    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    root->val = array[0];
    struct ListNode* cur = root;
    for (int i = 1; i < length; i++) {
        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = array[i];
        cur->next = node;
        cur = node;
    }

    return root;
}

int main() {
    int array[9] = {4, 5, 2, 2, 9, 3, 8, 9, 2};
    struct ListNode* l1 = createNode(array, 9);
    printf("aaaa\n");
    int array1[9] = {0, 7, 6, 1, 6, 5, 0, 6, 7};
    struct ListNode* l2 = createNode(array1, 9);
    printf("bbbbb\n");
    struct ListNode* result = addTwoNumbers(l1, l2);

    while (result != NULL) {
        printf("%d", result->val);
        result = result->next;
    }
}

