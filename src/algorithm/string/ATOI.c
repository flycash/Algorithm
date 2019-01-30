/*
 * =====================================================================================
 *
 *       Filename:  ATOI.c
 *
 *    Description:  String to Integer, atoi.
 * https://leetcode.com/problems/string-to-integer-atoi/
 *
 *        Version:  1.0
 *        Created:  01/28/2019 11:33:49 AM
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

int myAtoi(char* str) {
    int min = -2147483648;
    int max = 2147483647;

    long res = 0;

    bool neg = false;

    int index = 0;
    while (str[index] == ' ') {
        index++;
    }

    char first = str[index];
    if (first == '-') {
        neg = true;
        index++;
    } else if (first == '+') {
        index++;
    } else if (first < '0' || first > '9') {
        // first char is not valid character;
        return 0;
    }

    char cur;
    long tmp = res;
    while (str[index] != '\0') {
        cur = str[index];

        if (cur < '0' || cur > '9') {
            break;
        } else {
            res = res * 10 + (cur - 48);
        }

        if (neg) {
            tmp = -1 * res;
        } else {
            tmp = res;
        }

        if (tmp < min) {
            return min;
        }

        if (tmp > max) {
            return max;
        }
        index++;
    }

    if (neg) {
        res = -1 * res;
    }
    return res;
}

