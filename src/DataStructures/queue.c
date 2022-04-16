#include "queue.h" /* j� inclui tamb�m queueElem.h */
#include <stdio.h>
#include <stdlib.h>

/* Definicao da representacao de dados em mem�ria: */
typedef struct queueImpl {
    QueueElem *elements;
    unsigned int capacity;
    unsigned int size;
} QueueImpl;

PtQueue queueCreate(unsigned int initialCapacity) {
    PtQueue newQueue = (PtQueue)malloc(sizeof(QueueImpl));
    if (newQueue == NULL)
    {
        return NULL;
    }

    newQueue->elements = (QueueElem*)calloc(initialCapacity,
        sizeof(QueueElem));
    if (newQueue->elements == NULL)
    {
        free(newQueue);
        return NULL;
    }

    newQueue->capacity = initialCapacity;
    newQueue->size = 0;

    return newQueue;
}

int queueDestroy(PtQueue *ptQueue) {
    PtQueue tempQueue = *ptQueue;
    if (tempQueue == NULL) {
        return QUEUE_NULL;
    }

    free(tempQueue->elements);
    free(tempQueue);
    *ptQueue = NULL;

    return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    if (queue->size == queue->capacity) {
        //a taxa de crescimento � criterio do programador
        //neste caso dobra a capacidade, poderia ser apenas
        //espa�o para mais um elemento
        QueueElem *elements = (QueueElem*)realloc(queue->elements,
            queue->capacity * 2 * sizeof(QueueElem));
        if (elements == NULL) {
            //aten��o: bloco anterior � mantido pelo realloc
            return QUEUE_NO_MEMORY;
        }
        queue->elements = elements;
        queue->capacity *= 2;
    }

    queue->elements[queue->size++] = elem;
    return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    if (queueIsEmpty(queue)) {
        return QUEUE_EMPTY;
    }

    *ptElem = queue->elements[0];

    //para queue->size = 0, queue->size - 1 resultara em underflow do tipo uint
    //para nunca acontecera, pq essa situacao caira no if anterior
    for (unsigned int i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }

    queue->size--;
    return QUEUE_OK;
}

int queuePeek(PtQueue queue, QueueElem *ptElem) {
    if (queue == NULL) {
        return QUEUE_NULL;
    }

    if (queueIsEmpty(queue)) {
        return QUEUE_EMPTY;
    }

    *ptElem = queue->elements[0];
    return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
    if (queue == NULL) return QUEUE_NULL;
    *ptSize = queue->size;
    return QUEUE_OK;
}

int queueIsEmpty(PtQueue queue) {
    if (queue == NULL) return 1;
    return (queue->size > 0) ? 0 : 1;
}

int queueClear(PtQueue queue) {
    if (queue == NULL) return QUEUE_NULL;
    queue->size = 0;
    return QUEUE_OK;
}

void queuePrint(PtQueue queue) {
    if (queue == NULL) {
        printf("(Queue NULL) \n");
    }
    else if (queue->size == 0) {
        printf("(Queue Empty) \n");
    }
    else {
        //imprimir do inicio para o fim da fila:
        printf("          Indice BirthDate Sex Hospital                             District           Age  Bmi     Glicose Insulin  Mcp1\n\n");
        printf("Queue State:\n----inicio----\n");
        for (unsigned int i = 0; i < queue->size; i++) {
            queueElemPrint(queue->elements[i]);
        }
        printf("---- fim ----\n");
    }
}
