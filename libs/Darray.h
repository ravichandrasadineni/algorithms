#ifndef DARRAY_H
#define DARRAY_H
#define DARRAY_INITIAL_CAPACITY 100

typedef struct {

int size;
int capacity;
void** array;

} Darray;

void darray_init(Darray *darray);

void darray_append(Darray *darray, void* item);

void*  darray_get(Darray *darray, int index);

void darray_set(Darray *darray, int index, void* item);

void darray_double_capacity_if_full (Darray *darray);

void darray_free(Darray *darray);

#endif
