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
    int carry = 0;
    int first = l1->val;
    int second = l2->val;
    // struct ListNode* root = (struct ListNode*)malloc(sizeof(struct
    // ListNode));
    struct ListNode* root = NULL;
    struct ListNode* cur = root;
    while (carry != 0 || first != 0 || second != 0) {
        int sum = carry + first + second;
        carry = sum / 10;
        struct ListNode* node = malloc(sizeof(struct ListNode));
        if (carry == 1) {
            node->val = sum - 10;
        } else {
            node->val = sum;
        }

        if (cur == NULL) {
            root = cur = node;
        } else {
            cur->next = node;
            cur = node;
        }

        if (l1->next == NULL) {
            first = 0;
        } else {
            l1 = l1->next;
            first = l1->val;
        }

        if (l2->next == NULL) {
            second = 0;
        } else {
            l2 = l2->next;
            second = l2->val;
        }
    }
    return root;
}
