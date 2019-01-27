/*
 * =====================================================================================
 *
 *       Filename:  ReverseInteger.c
 *
 *    Description:  reverse integer.
 * https://leetcode.com/problems/reverse-integer/
 *
 *        Version:  1.0
 *        Created:  01/27/2019 09:26:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

int reverse(int x) {
    long min = -2147483648;

    long max = 2147483647;

    long res = 0;

    int quotient;
    while (x != 0) {
        quotient = x % 10;

        x = x / 10;

        res = (res * 10) + quotient;
    }

    if (res > max || res < min) {
        return 0;
    }
    return res;
}

