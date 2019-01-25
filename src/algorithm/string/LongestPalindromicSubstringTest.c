/*
 * =====================================================================================
 *
 *       Filename:  LongestPalindromicSubstringTest.c
 *
 *    Description:  test for LongestPalindromicSubstringTest.c
 *
 *        Version:  1.0
 *        Created:  01/24/2019 09:10:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "LongestPalindromicSubstring.c"

int main() {
    char* s = "babaddtattarrattatddetartrateedredividerb";
    char* res = longestPalindrome(s);
    printf("%s", res);
    return 0;
}
