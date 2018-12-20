#include <stddef.h>

typedef struct ArrayList {
    size_t size;
    float incrementFactor;
    void * data[];
} ArrayList;

ArrayList* createArrayList(size_t initSize, float incrementFactor);

ArrayList* createArrayList(void* data[]);

bool add(ArrayList* list, void* data);

bool insert(ArrayList* list, int index, void* data);

void replace(ArrayList* list, int index, void* data);

void* remove(ArrayList* list, int index);

size_t size(ArrayList* list);

void clear(ArrayList* list);

void* get(ArrayList* list, size_t index);

size_t indexOf(ArrayList* list, void* data);

size_t lastIndexOf(ArrayList* list, void* data);

void iterate(ArrayList* list, void* callback);

