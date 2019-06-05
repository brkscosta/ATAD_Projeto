#pragma once

typedef struct date {
	unsigned int day, month, year;
}Date;

Date dateCreate(unsigned int day, unsigned int month, unsigned int year);
Date dateRead();
void datePrint(Date *ptrDate);