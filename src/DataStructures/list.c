#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct listImpl {
    ListElem *elements;
    unsigned int size;
    unsigned int capacity;
} ListImpl;

PtList listCreate(unsigned int initialCapacity) {
    PtList newList = (PtList)malloc(sizeof(ListImpl));
    if (newList == NULL) return NULL;

    newList->elements = (ListElem*)calloc(initialCapacity, sizeof(ListElem));
    if (newList->elements == NULL) {
        free(newList);
        return NULL;
    }

    newList->size = 0;
    newList->capacity = initialCapacity;

    return newList;
}

int listDestroy(PtList *ptList) {
    PtList list = *ptList;

    if (list == NULL) return LIST_NULL;

    free(list->elements);
    free(list);

    *ptList = NULL;

    return LIST_OK;
}

int listAdd(PtList list, int rank, ListElem elem) {
    if (list == NULL) return LIST_NULL;
    if (rank < 0 || rank > list->size) return LIST_INVALID_RANK;
    /* melhorar com realoca��o do array 'elements': */
    if (list->size == list->capacity) {
        ListElem *newElements = (ListElem*)realloc(list->elements,
            (list->capacity + 1) * sizeof(ListElem));

        if (newElements == NULL) return LIST_NO_MEMORY;

        list->elements = newElements;
        list->capacity += 1;
    }

    for (int i = list->size; i > rank; i--) {
        list->elements[i] = list->elements[i - 1];
    }

    list->elements[rank] = elem;
    list->size++;
    return LIST_OK;
}

int listRemove(PtList list, int rank, ListElem *ptElem) {
    if (list == NULL) return LIST_NULL;
    if (list->size == 0) return LIST_EMPTY;
    if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

    *ptElem = list->elements[rank];

    for (int i = rank; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }

    list->size--;

    return LIST_OK;
}

int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
    if (list == NULL) return LIST_NULL;
    if (list->size == 0) return LIST_EMPTY;
    if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

    *ptOldElem = list->elements[rank];
    list->elements[rank] = elem;

    return LIST_OK;
}

int listGet(PtList list, int rank, ListElem *ptElem) {
    if (list == NULL) return LIST_NULL;
    if (list->size == 0) return LIST_EMPTY;
    if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

    (*ptElem) = list->elements[rank];

    return LIST_OK;
}

int listSize(PtList list, int *ptSize) {
    if (list == NULL) return LIST_NULL;

    *ptSize = list->size;

    return LIST_OK;
}

int listIsEmpty(PtList list) {
    if (list == NULL) return 1;
    if (list->size == 0) return 1;
    return 0;
}

int listClear(PtList list) {
    if (list == NULL) return LIST_NULL;

    list->size = 0;

    return LIST_OK;
}

void listPrint(PtList list) {

    if (list == NULL)
        printf("LIST NULL \n");
    else if (list->size == 0)
        printf("LIST EMPTY \n");
    else {
        printf("          Indice BirthDate Sex Hospital                             District           Age  Bmi     Glicose Insulin  Mcp1\n\n");
        for (int rank = 0; rank < list->size; rank++) {

            printf("At rank   %3d:", rank);
            listElemPrint(list->elements[rank]);
        }

    }
}

void listNormPrint(PtList list) {

    if (list == NULL)
        printf("LIST NULL \n");
    else if ( /*listIsEmpty(list)*/ list->size == 0)
        printf("LIST EMPTY \n");
    else {
        printf("Idx.  Age    Bmi    Glicose Insulin  Mcp1\n\n");
        //printf("Indice Age   Bmi   Glicose Insulin  Mcp1\n\n");
        for (int rank = 0; rank < list->size; rank++) {
            listElemNormPrint(list->elements[rank]);
        }

    }
}
