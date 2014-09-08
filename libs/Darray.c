#include"Darray.h"
#include<stdio.h>
#include<stdlib.h>


// sets size to 0 , capacity to intial capacity 
void darray_init(Darray *darray) {
    void *initialArray =  (void *)(calloc(sizeof(void *) , DARRAY_INITIAL_CAPACITY));
    darray->array = initialArray;
    darray->size = 0;
    darray->capacity = DARRAY_INITIAL_CAPACITY;
}

void darray_append(Darray *darray, void* item) {
    darray_double_capacity_if_full(darray);
    darray->array[darray->size] = item;
    darray->size++;
}

void*  darray_get(Darray *darray, int index) {
    if((index >= darray->size) || (index < 0)) {
        printf("Index Out of Bounds");
        exit(1);
    }
    return darray->array[index];
}
void darray_set(Darray *darray, int index, void* item) {
    while(index >= darray->size) {
        darray_append(darray,NULL);
    }
    darray->array[index] = item;
}

void darray_double_capacity_if_full (Darray *darray) {
    if(darray-> size >= darray-> capacity) {
        int doubleCapacity = darray->capacity *2;
        darray->array = realloc(darray->array, sizeof(void*) * doubleCapacity);
        darray->capacity = doubleCapacity;
    }
}

void darray_free(Darray *darray) {
    free(darray->array);
}
