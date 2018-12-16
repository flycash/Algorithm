
typedef struct ArrayList {
    int size;
    int incrementFactor;
    void * data[];
}

void add(ArrayList list, void* data);

void insert(ArrayList list, int index, void* data);

void replace(ArrayList list, int index, void* data);

void remove(ArrayList list, int index);

void size(ArrayList list);

bool isEmpty(ArrayList list);

void clear(ArrayList list);

