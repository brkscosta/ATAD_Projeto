/* PROJETO  ATAD 2018-19
* Identificacao dos Alunos:
*
*      Numero: 180221109 | Nome: Joanã Santos da Costa
*      Numero: 180221070 | Nome: Rafael Trindade
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<conio.h>
#include "util.h"
#include "map.h"
typedef char String[255];

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();
//...

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {

	/* declaracao de variaveis */
	PtList listPatients = listCreate(500);
	/* interpretador de comandos */
	String command;
	int quit = 0;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */
		}
		else if (equalsStringIgnoreCase(command, "LOAD")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			load(&listPatients);
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			clear(listPatients);
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {
			show(listPatients);
		}
		else if (equalsStringIgnoreCase(command, "SORT")) {
			sort(&listPatients);
		}
		else if (equalsStringIgnoreCase(command, "AVG")) {
			avg(listPatients);
		}
		else if (equalsStringIgnoreCase(command, "NORM")) {
			printf("Comando NORM nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "QUEUE")) {
			printf("Comando QUEUE nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "CHECKDISTRICT")) {
			printf("Comando CHECKDISTRICT nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADT")) {
			loadt(&listPatients);
		}
		else if (equalsStringIgnoreCase(command, "NORMT")) {
			printf("Comando NORMT nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "NEURALNET")) {
			printf("Comando NEURALNET nao implementado.\n");
		}
		else {
			clrscr();
			printf("\033[0;31m Command not found.\n");
			printf("\033[0m");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */
	listDestroy(&listPatients);
	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de modificacao para obter uma comparacao
	* 'case insensitive' */
	return (strcmp(str1, str2) == 0);
}

void printCommandsMenu() {
	printf("\n===================================================================================");
	printf("\n                          PROJECT: Patients and Clinical Data                      ");
	printf("\n===================================================================================");
	printf("\nA. Info about patients (LOAD, SHOW, CLEAR).");
	printf("\nB. Aggregated info about patients and clinical data (SORT, AVG, NORM, QUEUE, CHECKDISTRICT).");
	printf("\nC. Advanced indicator (LOADT, NORMT, NEURALNET)");
	printf("\nD. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}
