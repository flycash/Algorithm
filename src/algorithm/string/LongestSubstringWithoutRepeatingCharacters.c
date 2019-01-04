/*
 * =====================================================================================
 *
 *       Filename:  LongestSubstringWithoutRepeatingCharacters.c
 *
 *    Description:  longest substring without repeating characters
 *                  https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 *        Version:  1.0
 *        Created:  01/04/19 23:53:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://github.com/flycash,
 * https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:
 *
 * =====================================================================================
 */

int lengthOfLongestSubstring(char* s) {
    // char - index
    int chars[130] = {0};
    int result = 0;
    int i = 0;
    for (int j = 0; s[j]; j++) {
        int lastIndex = chars[s[j]];
        i = i > lastIndex ? i : lastIndex;
        int range = j - i + 1;
        result = result > range ? result : range;
        chars[s[j]] = j + 1;
    }
    return result;
}

