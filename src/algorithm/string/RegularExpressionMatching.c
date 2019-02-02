/*
 * =====================================================================================
 *
 *       Filename:  RegularExpressionMatching.c
 *
 *    Description:  regular expression matching.
 * https://leetcode.com/problems/regular-expression-matching/
 *
 *        Version:  1.0
 *        Created:  01/30/2019 11:01:23 PM
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
#include <string.h>

bool isMatch(char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    bool dp[slen + 1][plen + 1];

    for (int i = 0; i <= slen; i++) {
        for (int j = 0; j <= plen; j++) {
            dp[i][j] = false;
        }
    }

    dp[slen][plen] = true;

    for (int i = slen; i >= 0; i--) {
        for (int j = plen - 1; j >= 0; j--) {
            bool firstMatch = (i < slen && (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < plen && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
            } else {
                dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}

