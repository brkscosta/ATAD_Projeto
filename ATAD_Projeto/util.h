#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void clrscr();

char** split(char* str, int nFields, const char *delim);

void load(char *filename);