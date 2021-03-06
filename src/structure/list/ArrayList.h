#include <stdbool.h>
#include <stddef.h>

typedef struct ArrayList {
    size_t capacity;
    size_t size;
    float incrementFactor;
    void** data;
} ArrayList;

ArrayList* createArrayList(size_t initSize, float incrementFactor);

void destroyArrayList(ArrayList* list);

bool addIntoArrayList(ArrayList* list, void* data);

// if index >=capacity, the capacity will be extend to
// index * incrementFactor, and the element between [size, index) will be set to
// NULL]
bool insertIntoArrayList(ArrayList* list, size_t index, void* data);

// it will return the old element of the index,
// if the index>= capacity, it will do nothing and return NULL
void* replaceFromArrayList(ArrayList* list, size_t index, void* data);
// will return the element of the index. or NULL
void* removeFromArrayList(ArrayList* list, size_t index);

// all elements in the list will be set to NULL
size_t sizeOfArrayList(ArrayList* list);

void clearArrayList(ArrayList* list);

void* getFromArrayList(ArrayList* list, size_t index);

size_t indexOfArrayList(ArrayList* list, void* data);

size_t lastIndexOfArrayList(ArrayList* list, void* data);

// callback must be a function that looks like
// void doSomething(size_t index, void * data)
void iterateArrayList(ArrayList* list,
                      void (*callback)(size_t index, void* data));

ArrayList* mapArrayList(ArrayList* list, void* mapFunc);

ArrayList* filterArrayList(ArrayList* list, void* filter);

bool isEmptyArrayList(ArrayList* list);

bool isFullArrayList(ArrayList* list);
