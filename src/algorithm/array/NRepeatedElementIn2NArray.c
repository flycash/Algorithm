/*
 * =====================================================================================
 *
 *       Filename:  NRepeatedElementIn2NArray.c
 *
 *    Description:  leetcode
 * https://leetcode.com/contest/weekly-contest-116/problems/n-repeated-element-in-size-2n-array/
 *
 *                  as we known, one element repeated N times. So, we has at
 * leatst a[i]==a[i+1] or a[i] == a[i+2]
 *                  or a[0] == a[lengthOfArray-1]. The last case will appear in
 * array.length == 4, such like that [1, 2, 3, 1].
 *  And think about that
 *  [1,2,1,3], that is a[i] == a[i+2]
 *
 *        Version:  1.0
 *        Created:  12/27/18 12:21:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmai.com
 *   Organization:
 *
 * =====================================================================================
 */

int repeatedNTimes(int* A, int ASize) {
    if (A[0] == A[ASize - 1]) {
        return A[0];
    }
    if (A[0] == A[2]) {
        return A[0];
    }

    if (A[1] == A[3]) {
        return A[1];
    }
    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] == A[i + 1]) {
            return A[i];
        }
    }
    // it can't run to here
    return 0;
}

