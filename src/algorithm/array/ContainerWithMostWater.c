/*
 * =====================================================================================
 *
 *       Filename:  ContainerWithMostWater.c
 *
 *    Description:  container with most water.
 * https://leetcode.com/problems/container-with-most-water/
 *
 *        Version:  1.0
 *        Created:  02/02/2019 11:09:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int result = 0;
    while (left < right) {
        int lh = height[left];
        int rh = height[right];
        int width = right - left;
        int area;
        if (rh > lh) {
            area = lh * width;
        } else {
            area = rh * width;
        }

        result = result > area ? result : area;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}

