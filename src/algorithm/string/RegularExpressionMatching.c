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

bool match(int i, int j, char* s, char* p, int slen, int plen) { return false; }

bool isMatch(char* s, char* p) {
    int slen = strlen(s);
    int plen = strlen(p);
    if (plen == 0) {
        return slen == 0;
    }
    if (slen == 0) {
        return plen == 0;
    }
    return match(0, 0, s, p);
}

