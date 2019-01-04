/*
 * =====================================================================================
 *
 *       Filename:  LongestSubstringWithoutRepeatingCharactersTest.c
 *
 *    Description:  test for long...
 *
 *        Version:  1.0
 *        Created:  01/05/19 00:30:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "LongestSubstringWithoutRepeatingCharacters.c"
#include <stdio.h>
int main() {
    char* c = "";
    printf("a: %d", (int)c[0]);
    int res = lengthOfLongestSubstring(c);
    printf("result: %d", res);
}
