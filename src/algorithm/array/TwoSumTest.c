/*
 * =====================================================================================
 *
 *       Filename:  TwoSumTest.c
 *
 *    Description:  :two sum test
 *
 *        Version:  1.0
 *        Created:  12/21/18 12:41:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "TwoSumDouble.c"

int main() {
    int input[4] = {2, 7, 11, 15};
    int target = 9;
    int* result = twoSum(&input[0], 4, target);
    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
}
