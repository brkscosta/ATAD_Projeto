#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct listImpl {
    ListElem *elements;
    unsigned int size;
    unsigned int capacity;
} ListImpl;

/*
Cria uma nova inst�ncia da List.
Recebe:
initialCapacity - capacidade inicial (se aplic�vel)
Retorno:
refer�ncia da inst�ncia ou;
NULL no caso de inexist�ncia de mem�ria.
*/
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

/*
Destroi uma inst�ncia, libertando a mem�ria associada.
Argumentos:
ptList - endere�o da refer�ncia da inst�ncia;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listDestroy(PtList *ptList) {
    PtList list = *ptList;

    if (list == NULL) return LIST_NULL;

    free(list->elements);
    free(list);

    *ptList = NULL;

    return LIST_OK;
}

/*
Adiciona um elemento numa dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o (0 >= r <= size);
elem - elemento a emlistar;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_FULL caso a lista esteja cheia, ou;
LIST_NO_MEMORY caso nao haja mem�ria para guardar o elemento, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
LIST_OK em caso de sucesso;
*/
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


/*
Remove um elemento de uma dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
ptElem - elemento removido (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
LIST_OK em caso de sucesso;
*/
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


/*
Substitui o elemento no rank de uma dada inst�ncia, retornando o
elemento substituido.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
elem - elemento a inserir no rank;
ptOldElem - elemento anterior no rank (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
LIST_OK em caso de sucesso;
*/
int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
    if (list == NULL) return LIST_NULL;
    if (list->size == 0) return LIST_EMPTY;
    if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

    *ptOldElem = list->elements[rank];
    list->elements[rank] = elem;

    return LIST_OK;
}

/*
Obtem o elemento no rank de uma dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
ptElem - elemento no rank (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
LIST_OK em caso de sucesso;
*/
int listGet(PtList list, int rank, ListElem *ptElem) {
    if (list == NULL) return LIST_NULL;
    if (list->size == 0) return LIST_EMPTY;
    if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

    (*ptElem) = list->elements[rank];

    return LIST_OK;
}

/*
Quantos elementos est�o armazenados numa inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
ptSize - n�mero de elementos (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listSize(PtList list, int *ptSize) {
    if (list == NULL) return LIST_NULL;

    *ptSize = list->size;

    return LIST_OK;
}

/*
Verifica se a inst�ncia est� vazia (n�o cont�m elementos)
Argumentos:
list - refer�ncia da inst�ncia;
Retorno:
1 caso esteja vazia ou a refer�ncia seja NULL, ou;
0 caso n�o esteja vazia;
*/
int listIsEmpty(PtList list) {
    if (list == NULL) return 1;
    if (list->size == 0) return 1;
    return 0;
}

/*
Limpa uma inst�ncia (remove todos os elementos)
Argumentos:
list - refer�ncia da inst�ncia;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listClear(PtList list) {
    if (list == NULL) return LIST_NULL;

    list->size = 0;

    return LIST_OK;
}

/*
Mostra informa��o sobre uma inst�ncia
Argumentos:
list - refer�ncia da inst�ncia;
*/
void listPrint(PtList list) {

    if (list == NULL)
        printf("LIST NULL \n");
    else if ( /*listIsEmpty(list)*/ list->size == 0)
        printf("LIST EMPTY \n");
    else {
        printf("          Indice BirthDate Sex Hospital                             District           Age  Bmi     Glicose Insulin  Mcp1\n\n");
        for (int rank = 0; rank < list->size; rank++) {

            printf("At rank   %3d:", rank);
            listElemPrint(list->elements[rank]);
        }

    }
}

/*
Mostra informa��o sobre uma inst�ncia com a formata��o dos dados normalizados
Argumentos:
list - refer�ncia da inst�ncia;
*/
void listNormPrint(PtList list) {

    if (list == NULL)
        printf("LIST NULL \n");
    else if ( /*listIsEmpty(list)*/ list->size == 0)
        printf("LIST EMPTY \n");
    else {
        printf("Ind.  Age    Bmi    Glicose Insulin  Mcp1\n\n");
        //printf("Indice Age   Bmi   Glicose Insulin  Mcp1\n\n");
        for (int rank = 0; rank < list->size; rank++) {
            listElemNormPrint(list->elements[rank]);
        }

    }
}
