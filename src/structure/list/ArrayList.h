
typedef struct ArrayList {
    int size;
    float incrementFactor;
    void * data[];
} ArrayList;

ArrayList* createArrayList(int initSize, float incrementFactor);

void add(ArrayList* list, void* data);

void insert(ArrayList* list, int index, void* data);

void replace(ArrayList* list, int index, void* data);

void remove(ArrayList* list, int index);

void size(ArrayList* list);

void clear(ArrayList* list);

