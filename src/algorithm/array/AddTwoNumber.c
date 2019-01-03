/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumber.c
 *
 *    Description:  add two number
 *                  https://leetcode.com/problems/add-two-numbers/
 *
 *        Version:  1.0
 *        Created:  01/02/19 23:20:27
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

struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int first = l1->val;
    int second = l2->val;
    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    int sum = first + second;
    int carry = sum / 10;

    if (carry == 1) {
        root->val = sum - 10;
    } else {
        root->val = sum;
    }
    struct ListNode* cur = root;

    l1 = l1->next;
    l2 = l2->next;

    while (l1 != NULL || l2 != NULL || carry == 1) {
        if (l1 != NULL) {
            first = l1->val;
            l1 = l1->next;
        } else {
            first = 0;
        }

        if (l2 != NULL) {
            second = l2->val;
            l2 = l2->next;
        } else {
            second = 0;
        }
        sum = first + second + carry;
        carry = sum / 10;

        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        if (carry == 1) {
            node->val = sum - 10;
        } else {
            node->val = sum;
        }

        cur->next = node;
        cur = node;
    }

    return root;
}
