#pragma once

#include "patient.h"

/* definicao do tipo da chave */
typedef String MapKey;

/* definicao do tipo do valor*/

typedef ClinicalDataStats MapValue;

void mapKeyPrint(MapKey key);
void mapValuePrint(MapValue value);

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2);