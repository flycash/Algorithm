/*
 * =====================================================================================
 *
 *       Filename:  LinkedList.c
 *
 *    Description:  It will use the doube linked list;
 *
 *        Version:  1.0
 *        Created:  01/01/19 21:44:26
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
typedef struct Node {
    struct Node* prev;
    struct Node* next;
    void* data;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* result = (LinkedList*)malloc(sizeof(LinkedList));
    result->head = NULL;
    result->tail = result->head;
    result->size = 0;
    return result;
}

void addIntoLinkedList(LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->size = 1;
        return;
    }
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    list->size++;
}

bool insertIntoLinkedList(LinkedList* list, size_t index, void* data) {
    if (index >= list->size) {
        return false;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    Node* curPrev = current->prev;
    node->next = current;
    node->prev = curPrev;
    current->prev = node;

    if (index == 0) {
        list->head = node;
    }

    list->size++;

    return true;
}

// remove the last ele in list
void* removeTailFromLinkedList(LinkedList* list) {
    if (list->size == 0) {
        return NULL;
    }
    Node* tail = list->tail;
    Node* tailPrev = tail->prev;
    if (tailPrev != NULL) {
        tailPrev->next = NULL;
    } else {
        // the list only has one node;
        list->head = NULL;
    }
    list->tail = tailPrev;
    list->size--;
    return tail->data;
}

void* removeHeadFromLinkedList(LinkedList* list) {
    if (list->size == 0) {
        return NULL;
    }

    Node* head = list->head;
    Node* headNext = head->next;
    if (headNext == NULL) {
        list->tail = NULL;
    }

    list->head = headNext;
    list->size--;

    return head->data;
}

void removeFromLinkedList(LinkedList* list, void* data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            break;
        }
        current = current->next;
    }

    if (current != NULL) {
        Node* curPrev = current->prev;
        Node* curNext = current->next;
        if (curPrev != NULL) {
            curPrev->next = curNext;
        }
        if (curNext != NULL) {
            curNext->prev = curPrev;
        }

        if (current == list->tail) {
            list->tail = curPrev;
        }

        if (current == list->head) {
            list->head = curNext;
        }
    }
    list->size--;
}

void* removeFromLinkedListByIndex(LinkedList* list, size_t index) {
    if (index >= list->size) {
        return NULL;
    }

    if (list->size == 1) {
        Node* node = list->head;
        list->tail = NULL;
        list->head = NULL;
        list->size = 0;
        void* ret = node->data;
        free(node);
        return ret;
    }

    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    void* oldData = current->data;
    if (current == list->head) {
        list->head = current->next;
        list->head->prev = NULL;
    } else if (current == list->tail) {
        list->tail = current->prev;
        list->tail->next = NULL;
    } else {
        Node* curPrev = current->prev;
        Node* curNext = current->next;
        curPrev->next = curNext;
        curNext->prev = curPrev;
    }
    free(current);
    list->size--;
    return oldData;
}

void iterateLinkedList(LinkedList* list,
                       void (*callback)(size_t index, void* data)) {
    Node* current = list->head;
    size_t i = 0;
    while (i < list->size) {
        callback(i, current->data);
        current = current->next;
        i++;
    }
}
