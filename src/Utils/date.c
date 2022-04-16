
#include <stdio.h>
#include <stdlib.h>
#include "date.h"


Date dateCreate(unsigned int day, unsigned int month, unsigned int year) {
    Date date = { day, month, year };

    return date;
}

void datePrint(Date *ptrDate) {
    printf("%02d/%02d/%04d", ptrDate->day, ptrDate->month, ptrDate->year);
}