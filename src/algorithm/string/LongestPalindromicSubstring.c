/*
 * =====================================================================================
 *
 *       Filename:  LongestPalindromicSubstring.c
 *
 *    Description:  longest palindromic substring
 *    https://leetcode.com/problems/longest-palindromic-substring/
 *    the solution is
 * https://articles.leetcode.com/longest-palindromic-substring-part-ii/
 *
 *        Version:  1.0
 *        Created:  01/23/2019 03:01:40 PM
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

char* substr(char* s, int startIndex, int length) {
    char* res = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        res[i] = s[startIndex + i];
    }
    return res;
}

char* longestPalindrome(char* s) {
    int length = strlen(s);
    if (length == 1) {
        return s;
    }
    int tLength = length * 2 + 1;
    char* t = malloc(sizeof(char) * (tLength + 2));
    t[0] = '^';
    t[1] = '#';
    for (int i = 0; i < length; i++) {
        int index = (i + 1) * 2;
        t[index] = s[i];
        t[index + 1] = '#';
    }

    // using ^ and $ as seniel
    t[tLength - 1] = '$';

    int p[tLength];
    p[0] = 0;
    int center = 0;
    int right = 0;

    for (int i = 1; i < tLength - 1; i++) {
        int mirrorI = 2 * center - 1;
        if (right <= i) {
            p[i] = 1;
        } else if (right - i > p[mirrorI]) {
            p[i] = p[mirrorI];
        } else {
            p[i] = right - i;
        }

        while (t[i + p[i]] == t[i - p[i]]) p[i]++;

        if (i + p[i] > right) {
            right = i + p[i];
            center = i;
        }
    }

    // find the max
    int maxLength = 0;
    int centerIndex = 0;
    for (int i = 1; i < tLength - 1; i++) {
        if (p[i] > maxLength) {
            maxLength = p[i];
            centerIndex = i;
        }
    }
    return substr(s, (centerIndex - 1 - maxLength) / 2, maxLength);
}

