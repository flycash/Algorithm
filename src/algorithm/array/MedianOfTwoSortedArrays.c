/*
 * =====================================================================================
 *
 *       Filename:  MedianOfTwoSortedArrays.c
 *
 *    Description:  leetcode,
 *                  https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 *        Version:  1.0
 *        Created:  01/13/2019 09:29:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

int max(int i, int j) {
    if (i > j) {
        return i;
    }
    return j;
}

int min(int i, int j) {
    if (i >= j) {
        return j;
    }
    return i;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    // find the longer array
    //
    int* tmp;
    int sizeTmp;
    if (nums1Size > nums2Size) {
        tmp = nums2;
        nums2 = nums1;
        nums1 = tmp;

        sizeTmp = nums2Size;
        nums2Size = nums1Size;
        nums1Size = sizeTmp;
    }

    int iMin = 0;
    int iMax = nums1Size;
    int halfLen = (nums1Size + nums2Size + 1) / 2;

    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;

        if (i < iMax && nums2[j - 1] > nums1[i]) {
            iMin = i + 1;
        } else if (i > iMin && nums1[i - 1] > nums2[j]) {
            iMax = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = max(nums1[i - 1], nums2[j - 1]);
            }

            if ((nums1Size + nums2Size) % 2 == 1) {
                return maxLeft;
            }

            int minRight = 0;
            if (i == nums1Size) {
                minRight = nums2[j];
            } else if (j == nums2Size) {
                minRight = nums1[i];
            } else {
                minRight = min(nums2[j], nums1[i]);
            }

            return (minRight + maxLeft) / 2.0;
        }
    }
    return 0.0;
}
