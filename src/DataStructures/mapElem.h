#pragma once

#include "../PatientStruct/patient.h"

/* definição do tipo da chave */
typedef String MapKey;

/* definição do tipo do valor*/

typedef ClinicalDataStats MapValue;

void mapKeyPrint(MapKey key);
void mapValuePrint(MapValue value);

/* funcao de comparação de chaves */
int mapKeyEquals(MapKey key1, MapKey key2);