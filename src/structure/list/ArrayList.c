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
 *         Author:  flycash (https://www.jianshu.com/u/f2b47e5528d8),
 * ming_flycash@foxmail.com Organization:
 *
 * =====================================================================================
 */
#include "ArrayList.h"
#include <stdlib.h>
#define DEFAULT_INCREMENT_FACTOR 1.2

void extendArrayListToTargetCapacity(ArrayList* list, size_t newCapacity);

void extendArrayList(ArrayList* list);

/**
 * =======implement of ArrayList.h =============
 */
ArrayList* createArrayList(size_t initSize, float incrementFactor) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (incrementFactor <= 0) {
        list->incrementFactor = DEFAULT_INCREMENT_FACTOR;
    } else {
        list->incrementFactor = incrementFactor;
    }
    list->size = 0;
    list->capacity = initSize;
    void* mem = malloc(sizeof(void*) * initSize);
    list->data = (void**)mem;
    return list;
}

void destroyArrayList(ArrayList* list) {
    for (size_t i = 0; i < list->size; i++) {
        void* data = list->data[i];
        free(data);
    }

    free(list);
}
bool addIntoArrayList(ArrayList* list, void* data) {
    if (isFullArrayList(list)) {
        extendArrayList(list);
    }
    list->data[list->size] = data;
    list->size += 1;
    return true;
}

bool isFullArrayList(ArrayList* list) { return list->size == list->capacity; }

bool insertIntoArrayList(ArrayList* list, size_t index, void* data) {
    if (index >= list->size) {
        size_t newCapacity = index * list->incrementFactor;
        if (newCapacity == index) {
            newCapacity++;
        }
        extendArrayListToTargetCapacity(list, newCapacity);
        // make the element between [size, index) to NULL;
        for (size_t i = list->size; i < index; i++) {
            list->data[i] = NULL;
        }
        list->data[index] = data;
        list->size = index + 1;
    } else {
        // make sure there has enough space
        if (isFullArrayList(list)) {
            extendArrayList(list);
        }
        // move elements
        for (int i = list->size - 1; i >= (int)index; i--) {
            list->data[i + 1] = list->data[i];
        }
        list->data[index] = data;
        list->size++;
    }

    return true;
}

void* replaceFromArrayList(ArrayList* list, size_t index, void* data) {
    if (index >= list->size) {
        return NULL;
    }

    void* oldData = list->data[index];
    list->data[index] = data;
    return oldData;
}

void* removeFromArrayList(ArrayList* list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    void* oldData = list->data[index];
    for (size_t i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->data[list->size - 1] = NULL;
    list->size--;
    return oldData;
}

size_t sizeOfArrayList(ArrayList* list) { return list->size; }

void clearArrayList(ArrayList* list) {
    for (size_t i = 0; i < list->size; i++) {
        list->data[i] = NULL;
    }
    list->size = 0;
}

void* getFromArrayList(ArrayList* list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }
    return list->data[index];
}

size_t indexOfArrayList(ArrayList* list, void* data) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->data[i] == data) {
            return i;
        }
    }
    return -1;
}

size_t lastIndexOfArrayList(ArrayList* list, void* data) {
    for (size_t i = list->size - 1; i >= 0; i--) {
        if (list->data[i] == data) {
            return i;
        }
    }

    return -1;
}

// private method, you should not call that;
void extendArrayListToTargetCapacity(ArrayList* list, size_t newCapacity) {
    void** newData = malloc(sizeof(void*) * newCapacity);
    for (size_t i = 0; i < list->size; i++) {
        newData[i] = list->data[i];
    }
    list->data = newData;
    list->capacity = newCapacity;
}

void extendArrayList(ArrayList* list) {
    size_t newCapacity = list->capacity * list->incrementFactor;
    if (newCapacity == list->capacity) {
        // make sure that the capacity extended;
        newCapacity++;
    }
    extendArrayListToTargetCapacity(list, newCapacity);
}

