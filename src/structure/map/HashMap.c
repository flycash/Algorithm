/*
 * =====================================================================================
 *
 *       Filename:  HashMap.c
 *
 *    Description:  HashMap
 *
 *        Version:  1.0
 *        Created:  01/05/19 00:47:48
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

typedef struct Entry {
    int hashCode;
    void* key;
    void* value;
    struct Entry* next;
} Entry;

typedef struct HashMap {
    int size;
    int (*hashCode)(void* key);
    bool (*equals)(void* originKey, void* targetKey);
    Entry* buckets;
} HashMap;

HashMap* createHashMap(int (*hashCode)(void* key),
                       bool (*equals)(void* originKey, void* targetKey)) {
    HashMap* result = (HashMap*)malloc(sizeof(HashMap));
    return result;
}
