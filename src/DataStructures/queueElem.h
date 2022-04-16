#pragma once
#include "../PatientStruct/patient.h"

/* Defini��o do tipo de dados (exemplo para inteiros) */
typedef Patient QueueElem;

/* Defini��o de quaisquer outras opera��es que o tipo deve
suportar, e.g., imprimir, comparar, etc. */
void queueElemPrint(QueueElem elem);
