#pragma once

#define LIST_OK				0
#define LIST_NULL			1
#define LIST_NO_MEMORY		2
#define LIST_EMPTY			3
#define LIST_FULL			4
#define LIST_INVALID_RANK	5

/* Contem defini��o do tipo a guardar na list */
#include "listElem.h"

/* Forward declaration do registo (representa��o dos dados)
da list.
Tem de estar definida em concreto num ficheiro *.c aquando
da compila��o do programa.
*/
struct listImpl;

/* Definicao de refer�ncia para uma inst�ncia da list */
typedef struct listImpl *PtList;

/*
Cria uma nova inst�ncia da List.
Recebe:
initialCapacity - capacidade inicial (se aplic�vel)
Retorno:
refer�ncia da inst�ncia ou;
NULL no caso de inexist�ncia de mem�ria.
*/
PtList listCreate(unsigned int initialCapacity);

/*
Destroi uma inst�ncia, libertando a mem�ria associada.
Argumentos:
ptList - endere�o da refer�ncia da inst�ncia;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listDestroy(PtList *ptList);

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
int listAdd(PtList list, int rank, ListElem elem);

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
int listRemove(PtList list, int rank, ListElem *ptElem);

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
int listGet(PtList list, int rank, ListElem *ptElem);

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
int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem);

/*
Quantos elementos est�o armazenados numa inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
ptSize - n�mero de elementos (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listSize(PtList list, int *ptSize);

/*
Verifica se a inst�ncia est� vazia (n�o cont�m elementos)
Argumentos:
list - refer�ncia da inst�ncia;
Retorno:
1 caso esteja vazia ou a refer�ncia seja NULL, ou;
0 caso n�o esteja vazia;
*/
int listIsEmpty(PtList list);

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
list - referência da instância;
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listClear(PtList list);

/*
Mostra informação sobre uma instância com a formatação dos dados normalizados
Argumentos:
list - referência da instância;
*/
void listPrint(PtList list);

/*
Mostra informação sobre uma instância
Argumentos:
list - referência da instância;
*/
void listNormPrint(PtList list);
