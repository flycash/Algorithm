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
#include <stdlib.h>
#include <assert.h>
#define DEFAULT_INCREMENT_FACTOR 1.2

ArrayList* createArrayList(size_t initSize, float incrementFactor) {

    ArrayList* list =(ArrayList*) malloc(sizeof(ArrayList));
    assert(list);
    if(incrementFactor <=0) {
        list->incrementFactor = DEFAULT_INCREMENT_FACTOR;
    } else {
        list->incrementFactor = incrementFactor;
    }
    list->size = 0;
    void* mem = malloc(sizeof(void *) * initSize);
    assert(mem);
    list->data = (void **) mem;
    return list;
}

bool addIntoArrayList(ArrayList* list, void* data) {
    if(isFullArrayList(list)){

    }
}

bool isFulleArrayList(ArrayList* list) {
    return list->size == list->capacity;
}

void extendArrayList(ArrayList* list) {
    size_t newCapacity = list->capacity * list->incrementFactor;
    void* newDatas = malloc(sizeof(void*) * newCapacity);
}


