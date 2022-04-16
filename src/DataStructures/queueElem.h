#pragma once
#include "../PatientStruct/patient.h"

/* Definição do tipo de dados (exemplo para inteiros) */
typedef PatientModel QueueElem;

/* Definição de quaisquer outras operações que o tipo deve
suportar, e.g., imprimir, comparar, etc. */
void queueElemPrint(QueueElem elem);
