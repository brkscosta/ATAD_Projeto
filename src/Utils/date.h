#pragma once
#include <stdio.h>
#include <string.h>

typedef struct date {
    unsigned int day, month, year;
} Date;

/* 
Cria uma tipo de dados do tipo Date
Recebe
int day - número do dia
int month - número do mês
int year - número do ano
Retorna
Um tipo de dados do tipo Date
*/
Date dateCreate(unsigned int day, unsigned int month, unsigned int year);

/* 
Imprime uma data
Recebe
ptrDate - data
Retorna
*/
void datePrint(Date *ptrDate);