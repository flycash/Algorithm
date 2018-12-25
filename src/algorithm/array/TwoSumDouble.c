/*
 * =====================================================================================
 *
 *       Filename:  two_sum.c
 *
 *    Description:  leetcode two sum, see https://leetcode.com/problems/two-sum/
 *   inefficient implement
 *
 *        Version:  1.0
 *        Created:  2018/12/19 10时58分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8),
 * ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = result[1] = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        // j = i+1
        for (int j = i + 1; j < numsSize; j++) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
}

