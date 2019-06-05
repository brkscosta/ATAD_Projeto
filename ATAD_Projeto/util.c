#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


void clrscr()
{
	system("@cls||clear");
}

char** split(char *string, int nFields, const char *delim) {

	char **tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char *next_token = NULL; //para controlo interno da fun��o strtok_s

	char *token = (char*)strtok_s(string, delim, &next_token);

	while (token) {
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}
	return tokens;
}

void load(char *filename1) {
	FILE *fPatient, *fClinicalData;
	int error = 0;
	char filename[20];
	//Pedir nome ao utilizador
	/*char filename[20] = "patients.csv";
	filename[(strlen(filename) - 1)] = '\0';
	printf("%c", filename);*/
	do {
		printf("\n\n Importar fichero do paciente(nome do ficheiro): ");
		fgets(filename, sizeof(filename), stdin);
		filename[strlen(filename) - 1] = '\0';
		error = fopen_s(&fPatient, filename, "r");
		if (error != 0) {
			clrscr();
			printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
			printf("\033[0m");
		}
	} while (error != 0);

	char nextLine[1024];
	int countPatient = 0;
	while (fgets(nextLine, sizeof(nextLine), fPatient)) {
		if (strlen(nextLine) < 1)
			continue;
		char **tokens = split(nextLine, 5, ";");
		//tokens[0] -> id
		//tokens[1] -> data
		//tokens[2] -> genero
		//tokens[3] -> hospital
		//tokens[4] -> distrito

		int id = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		char gender = tokens[2][0];

		printf("id: %d |data: %02d/%02d/%04d|G:%c | H: %s| D: %s \n",
			id, day, month, year, gender, tokens[3], tokens[4]);
		free(tokens);
		countPatient++;
	}
	printf("\n\n %d numero de pacientes\n", countPatient);
	fclose(fPatient);
}
