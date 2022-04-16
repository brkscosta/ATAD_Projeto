#pragma once

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4


#include "queueElem.h"

struct queueImpl;
typedef struct queueImpl *PtQueue;

/* 
Cria uma nova instancia de Queue
Recebe
initialCapacity - capacidade inicial
Retorna
referência da instância ou
NULL no caso de inexist�ncia de memória.
*/
PtQueue queueCreate(unsigned int initialCapacity);

/* 
Destroi uma instância, libertando a memória associada.
Argumentos:
ptQueue - endere�o da referência da instância;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueDestroy(PtQueue *ptQueue);

/*
Insere um elemento no fim da fila numa dada instância.
Argumentos:
queue - referência da instância;
elem - elemento a inserir na fila;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_FULL caso a fila esteja cheia, ou;
QUEUE_NO_MEMORY caso nao haja memória para guardar o elemento, ou;
QUEUE_OK em caso de sucesso;
*/
int queueEnqueue(PtQueue queue, QueueElem elem);

/*
Retira do inicio da fila um elemento numa dada instância.
Argumentos:
stack - referência da instância;
ptElem - elemento removido (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_EMPTY caso a fila esteja vazia, ou;
QUEUE_OK em caso de sucesso;
*/
int queueDequeue(PtQueue queue, QueueElem *ptElem);

/*
Espreita o elemento do fim numa dada instância.
Argumentos:
queue - referência da instância;
ptElem - elemento no topo (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_EMPTY caso a fila esteja vazia, ou;
QUEUE_OK em caso de sucesso;
*/
int queuePeek(PtQueue queue, QueueElem *ptElem);

/*
Quantos elementos estão armazenados numa instância.
Argumentos:
queue - referência da instância;
ptSize - n�mero de elementos (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueSize(PtQueue queue, int *ptSize);

/*
Verifica se a instância est� vazia (n�o cont�m elementos)
Argumentos:
queue - referência da instância;
Retorno:
1 caso esteja vazia ou a referência seja NULL, ou;
0 caso não esteja vazia;
*/
int queueIsEmpty(PtQueue queue);

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
queue - referência da instância;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueClear(PtQueue queue);

/*
Mostra informação sobre uma instância
Argumentos:
stack - referência da instância;
*/
void queuePrint(PtQueue queue);


