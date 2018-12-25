/*
 * =====================================================================================
 *
 *       Filename:  TwoSumSort.c
 *
 *    Description:  the solution by sorting the array,
 * https://leetcode.com/problems/two-sum/.
 * - sort the nums
 * - find the number a and b that meet a+b = target
 * - find the index of a and b
 *
 *        Version:  1.0
 *        Created:  2018/12/23 00时59分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8),
 * ming_flycash@foxmail.com Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    int* a1 = (int*)a;
    int* b1 = (int*)b;
    return (int)(*a1 - *b1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* result = malloc(sizeof(int) * 2);
    result[0] = 0;
    result[1] = 0;

    int* copy = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        copy[i] = nums[i];
    }
    // sort
    qsort(nums, numsSize, sizeof(int), comp);
    int i = 0;
    int j = numsSize - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            break;
        }

        if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    // the i and j is the target
    int first = nums[i];
    int second = nums[j];

    printf("%d, %d, %d, %d", i, j, first, second);

    for (int k = 0; k < numsSize; k++) {
        int num = copy[k];
        if (num == first) {
            result[0] = k;
        }
        if (num == second && k > result[0]) {
            result[1] = k;
            break;
        }
    }
    return result;
}
