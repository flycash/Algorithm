/*
 * =====================================================================================
 *
 *       Filename:  ReverseNodesInKGroup.c
 *
 *    Description:  https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 *        Version:  1.0
 *        Created:  02/26/2019 10:12:05 PM
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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 1) {
        return head;
    }

    struct ListNode* current = head;
    struct ListNode* partHead;
    struct ListNode* partTail;
    struct ListNode* newListTail = head = NULL;
    int count = 1;
    while (current != NULL) {
        struct ListNode* next = current->next;
        if (count == 1) {
            partTail = current;
        }
        if (count != k) {
            current->next = partHead;
            partHead = current;
            count++;
        } else {
            newListTail->next = partHead;
            newListTail = partTail;
            // reset the count
            if (head == NULL) {
                head = partHead;
            }
            count = 1;
            partHead = NULL;
            partTail = NULL;
        }

        current = next;
    }
    return head;
}

