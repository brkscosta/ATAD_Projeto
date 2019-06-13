#include "mapElem.h"

void mapKeyPrint(MapKey key) {
	printf("%s \n", key);
}

void mapValuePrint(MapValue value) {
	clinicalataStatisticsPrint(&value);
}

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2) {
	//no caso de MapKey == int. Alterar de acordo
	//com o tipo efetivo
	/*int result_strcmp = strcmp(key1, key2);
	if (result_strcmp == 0) {
		return -1;
	}*/
	return  strcmp(key1, key2);
}