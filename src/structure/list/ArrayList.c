/*
 * =====================================================================================
 *
 *       Filename:  ArrayList.c
 *
 *    Description:  the implementation of ArrayList
 *
 *        Version:  1.0
 *        Created:  2018/12/18 23时05分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8), ming_flycash@foxmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "ArrayList.h"

#define DEFAULT_INCREMENT_FACTOR = 1.2

ArrayList* createArrayList(int initSize, float incrementFactor) {
    ArrayList list;
    if(incrementFactor <=0) {
        list.incrementFactor = DEFAULT_INCREMENT_FACTOR;
    } else {
        list.incrementFactor = incrementFactor;
    }
    list.size = 0;
    list.data = malloc(sizeof(void*)*initSize);
    return &list
}


