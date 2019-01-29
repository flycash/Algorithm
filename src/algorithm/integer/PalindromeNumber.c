/*
 * =====================================================================================
 *
 *       Filename:  PalindromeNumber.c
 *
 *    Description:  palindrome number.
 * https://leetcode.com/problems/palindrome-number/
 *
 *        Version:  1.0
 *        Created:  01/29/2019 02:08:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int right = 0;
    int left = x;
    int remainder;
    while (left > right) {
        remainder = left % 10;
        if (right == 0 && remainder == 0) {
            return false;
        }
        right = right * 10 + remainder;
        left = left / 10;
    }

    if (left == right) {
        return true;
    }

    if (left == right / 10) {
        return true;
    }

    return false;
}
