#pragma once
#include <stdio.h>
#include <string.h>

typedef struct date {
	unsigned int day, month, year;
}Date;

Date dateCreate(unsigned int day, unsigned int month, unsigned int year);
void datePrint(Date *ptrDate);