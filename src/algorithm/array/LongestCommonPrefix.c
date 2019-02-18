/*
 * =====================================================================================
 *
 *       Filename:  LongestCommonPrefix.c
 *
 *    Description:  longest common prefix.
 *    https://leetcode.com/problems/longest-common-prefix/
 *
 *        Version:  1.0
 *        Created:  02/18/2019 07:15:01 PM
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
#include <stdlib.h>
#include <string.h>

char* fetchResult(char* first, int index) {
    if (index == 0) {
        return "";
    }

    char* result = (char*)malloc(sizeof(char) * (index + 1));
    memcpy(result, first, index + 1);
    result[index] = '\0';
    return result;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    char* firstStr = strs[0];
    int index = 0;
    char current = firstStr[index];
    while (current != '\0') {
        for (int i = 1; i < strsSize; i++) {
            char otherChar = strs[i][index];
            if (current != otherChar) {
                return fetchResult(firstStr, index);
            }
        }

        index++;
        current = firstStr[index];
    }

    return fetchResult(firstStr, index);
}

