/*
 * =====================================================================================
 *
 *       Filename:  ZigzagConversion.c
 *
 *    Description:  zigzag convertion
 *    https://leetcode.com/problems/zigzag-conversion/
 *
 *        Version:  1.0
 *        Created:  01/26/2019 10:41:26 PM
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
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int length = strlen(s);
    char* ret = (char*)malloc(sizeof(char) * (length + 1));

    int cycleLength = 2 * numRows - 2;

    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < length; j += cycleLength) {
            ret[index] = s[j + 1];
            index++;

            if (i != 0 && i != numRows - 1 && j + cycleLength - i < length) {
                ret[index] = s[j + cycleLength - i];
                index++;
            }
        }
    }

    ret[length] = '\0';
    return ret;
}

