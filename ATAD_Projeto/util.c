#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void load(PtList *patients) {
	clrscr();
	printf("\n===================================================================================");
	printf("\n                          LOAD                                                     ");
	printf("\n===================================================================================\n");

	FILE *fPatient, *fClinicalData;
	int error = 0;
	char filename[20];

	printf(" \033[1;33mCommand \"BACK\" to return to the home menu \n");
	printf("\033[0m");

	do {
		/*printf("\n\nImport patient file (file name): ");
		fgets(filename, sizeof(filename), stdin);

		filename[strlen(filename) - 1] = '\0';*/

		if (filename == "BACK") return;

		error = fopen_s(&fPatient, "patients.csv", "r");
		if (error != 0) {
			printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
			printf("\033[0m");
		}
	} while (error != 0);

	do {
		/*printf("\n\nImport Clinical Data file (file name): ");
		fgets(filename, sizeof(filename), stdin);

		filename[strlen(filename) - 1] = '\0';*/

		if (filename == "BACK") return;

		error = fopen_s(&fClinicalData, "clinicalData.csv", "r");
		if (error != 0) {
			printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
			printf("\033[0m");
		}
	} while (error != 0);

	char nextLine[1024];
	int countPatient = 0;
	while (fgets(nextLine, sizeof(nextLine), fPatient)) {
		if (strlen(nextLine) < 1)
			continue;
		char **tokens = split(nextLine, 6, ";");
		//tokens[0] -> Id
		//tokens[1] -> Date 
		//tokens[2] -> gender
		//tokens[3] -> hospital
		//tokens[4] -> district
		int id = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		char gender = tokens[2][0];
		tokens[4][strlen(tokens[4]) - 1] = '\0';
		ListElem patient = patientCreate(
			id, dateCreate(day, month, year), gender, tokens[3], tokens[4]);
		listAdd(*patients, countPatient, patient);
		free(tokens);
		countPatient++;
	}


	int countClinicalData = 0;
	int rank = -1;
	ListElem patientElem, oldClinicalData;
	while (fgets(nextLine, sizeof(nextLine), fClinicalData)) {
		if (strlen(nextLine) < 1)
			continue;
		char **tokens = split(nextLine, 6, ";");

		//tokens[0] -> id_patient
		//tokens[1] -> data / age
		//tokens[2] -> bmi
		//tokens[3] -> glucose
		//tokens[4] -> insulin
		//tokens[5] -> mcp1


		rank = findPatientRankById(*patients, atoi(tokens[0]));

		if (rank != -1) {
			//Caso o rank seja valido atualiza os dados clinicos

			listGet(*patients, rank, &patientElem);

			int day, month, year;
			sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
			Date data2 = dateCreate(day, month, year);

			float age = getAge(patientElem.birthdate, data2);
			patientElem.clinicalData.age = updateClinicalData(patientElem.clinicalData.age, age, patientElem.clinicalData.clinicalDataCount);

			patientElem.clinicalData.bmi = updateClinicalData(patientElem.clinicalData.bmi, atof(tokens[2]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.glucose = updateClinicalData(patientElem.clinicalData.glucose, atof(tokens[3]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.insulin = updateClinicalData(patientElem.clinicalData.insulin, atof(tokens[4]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.mcp1 = updateClinicalData(patientElem.clinicalData.mcp1, atof(tokens[5]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.clinicalDataCount += 1;


			listSet(*patients, rank, patientElem, &oldClinicalData);

		}


		free(tokens);
		countClinicalData++;
	}



	printf("\n\n %d patients and information about %d clinical data was reading! \n", countPatient, countClinicalData);
	fclose(fPatient);
	fclose(fClinicalData);
	system("pause");
	clrscr();
}

void show(PtList patients) {
	clrscr();
	printf("\n================================================================================================");
	printf("\n                          SHOW                                                                  ");
	printf("\n================================================================================================\n\n");
	listPrint(patients);
	printf("\n\n");
	system("pause");
	clrscr();
}

void clear(PtList patients) {
	int size;
	listSize(patients, &size);
	listClear(patients);

	printf("%d data deleted\n", size);
	system("pause");
	clrscr();
}

void loadt(PtList *patients) {
	clrscr();
	printf("\n===================================================================================");
	printf("\n                          LOADT                                                    ");
	printf("\n===================================================================================\n");

	FILE *fPatient_train, *fClinicalData_train;
	int error = 0;
	char filename[20];

	printf(" \033[1;33mCommand \"BACK\" to return to the home menu \n");
	printf("\033[0m");

	do {
		/*printf("\n\nImport patient file (file name): ");
		fgets(filename, sizeof(filename), stdin);

		filename[strlen(filename) - 1] = '\0';*/

		if (filename == "BACK") return;

		error = fopen_s(&fPatient_train, "patients_train.csv", "r");
		if (error != 0) {
			printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
			printf("\033[0m");
		}
	} while (error != 0);

	do {
		/*printf("\n\nImport Clinical Data file (file name): ");
		fgets(filename, sizeof(filename), stdin);

		filename[strlen(filename) - 1] = '\0';*/

		if (filename == "BACK") return;

		error = fopen_s(&fClinicalData_train, "clinicalData_train.csv", "r");
		if (error != 0) {
			printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
			printf("\033[0m");
		}
	} while (error != 0);

	char nextLine[1024];
	int countPatient = 0;
	while (fgets(nextLine, sizeof(nextLine), fPatient_train)) {
		if (strlen(nextLine) < 1)
			continue;
		char **tokens = split(nextLine, 6, ";");
		//tokens[0] -> Id
		//tokens[1] -> Date 
		//tokens[2] -> gender
		//tokens[3] -> hospital
		//tokens[4] -> district
		int id = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		char gender = tokens[2][0];
		tokens[4][strlen(tokens[4]) - 1] = '\0';
		ListElem patient = patientCreate(
			id, dateCreate(day, month, year), gender, tokens[3], tokens[4]);
		listAdd(*patients, countPatient, patient);
		free(tokens);
		countPatient++;
	}
	int countClinicalData = 0;
	int rank = -1;
	ListElem patientElem, oldClinicalData;
	while (fgets(nextLine, sizeof(nextLine), fClinicalData_train)) {
		if (strlen(nextLine) < 1)
			continue;
		char **tokens = split(nextLine, 11, ";");

		//tokens[0]  -> id_patient
		//tokens[1]  -> data / age
		//tokens[2]  -> bmi
		//tokens[3]  -> glucose
		//tokens[4]  -> insulin
		//tokens[5]  -> mcp1
		//tokens[6]  -> type_disease
		//tokens[7]  -> c1
		//tokens[8]  -> c2
		//tokens[9]	 -> c3
		//tokens[10] -> c4


		rank = findPatientRankById(*patients, atoi(tokens[0]));

		if (rank != -1) {
			//Caso o rank seja valido atualiza os dados clinicos

			listGet(*patients, rank, &patientElem);

			int day, month, year;
			sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
			Date data2 = dateCreate(day, month, year);

			float age = getAge(patientElem.birthdate, data2);
			patientElem.clinicalData.age = updateClinicalData(patientElem.clinicalData.age, age, patientElem.clinicalData.clinicalDataCount);

			patientElem.clinicalData.bmi = updateClinicalData(patientElem.clinicalData.bmi, atof(tokens[2]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.glucose = updateClinicalData(patientElem.clinicalData.glucose, atof(tokens[3]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.insulin = updateClinicalData(patientElem.clinicalData.insulin, atof(tokens[4]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.mcp1 = updateClinicalData(patientElem.clinicalData.mcp1, atof(tokens[5]), patientElem.clinicalData.clinicalDataCount);
			patientElem.clinicalData.disease_type = atoi(tokens[6]);
			patientElem.clinicalData.clinicalDataCount += 1;

			listSet(*patients, rank, patientElem, &oldClinicalData);
		}
		free(tokens);
		countClinicalData++;
	}
	printf("\n\n %d patients and information about %d clinical data was reading! \n", countPatient, countClinicalData);
	fclose(fPatient_train);
	fclose(fClinicalData_train);
	system("pause");
	clrscr();

}

void sort(PtList *patients) {
	clrscr();
	char command[20];
	int option;
	int quit = 0;

	printf("\n===================================================================================");
	printf("\n                          SORT                                                     ");
	printf("\n===================================================================================\n");
	printf("Select sorting criteria\n");
	printf("1- Birthdate\n");
	printf("2- Hospital\n");
	printf("3- District\n");
	printf("4- To return to the home menu\n\n");

	PtList auxiliar = copyData(*patients);

	do {
		printf("COMMAND> ");
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';
		option = atoi(command);

		if (option == 1) {
			sortByBirthdate(auxiliar);
			quit = 1;
		}
		else if (option == 2) {
			sortByHospital(auxiliar);
			quit = 1;
		}
		else if (option == 3) {
			sortByDistrict(auxiliar);
			quit = 1;
		}
		else if (option == 4) {
			quit = 1;
		}
		else {
			printf("\033[0;31m Command not found.\n");
			printf("\033[0m");
		}
	} while (quit != 1);
	listPrint(auxiliar);
	listDestroy(&auxiliar);
	system("pause");
	clrscr();

}

void avg(PtList patients) {
	printf("\n===================================================================================");
	printf("\n                             AVG                                                   ");
	printf("\n===================================================================================\n");

	//TODO:
}


void checkDistrict(PtList patients) {
	
	clrscr();
	char command[20];
	int option;
	int quit = 0;
	printf("\n===================================================================================");
	printf("\n                             CHECKDISTRICT                                         ");
	printf("\n===================================================================================\n");

	//TODO:
	PtMap map = mapCreate(20);
	do {
		printf("COMMAND> ");
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = '\0';
		//option = atoi(command);
		
		if (mapContains(map, command) == 1) {
			print("Faz coisas");
			quit = 1;
		} else {
			printf("\033[0;31m Localidade nao encontrada.\n");
			printf("\033[0m");
		}

	} while (quit != 1);
	
	mapPrint(map);
	mapDestroy(map);
	system("pause");
	clrscr();
}

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

float getAge(Date date1, Date date2) {
	int age;
	age = date2.year - date1.year;

	if (date2.month < date1.month) {
		return age - 1;

	}
	else if (date2.day < date1.day)
	{
		return age - 1;
	}

	return age;
}

float updateClinicalData(float avg, float v, int n) {
	float value;

	value = ((avg * n) + v) / (n + 1);

	return value;
}

int findPatientRankById(PtList *patient, int patientId) {
	int size;
	ListElem patientElem;
	listSize(patient, &size);

	for (int i = 0; i < size; i++) {
		listGet(patient, i, &patientElem);
		if (patientElem.id == patientId) {
			return i;
		}
	}
	return -1;
}

void sortByBirthdate(PtList patients) {
	int size;
	listSize(patients, &size);
	ListElem patient1, patient2;

	for (int i = 0; i < size; i++) {
		int indexMin = i;
		for (int j = i; j < size; j++) {
			listGet(patients, indexMin, &patient1);
			listGet(patients, j, &patient2);

			int result = compareBirthdate(patient1, patient2);
			if (result > 0) {
				indexMin = j;
			}
		}
		swapPatients(patients, indexMin, i, patient1, patient2);
	}
}

int compareBirthdate(ListElem patient1, ListElem patient2) {
	//Return -1 se o patient1 é menor que patient2 
	//Return  1 se o patient2 é menor que patient1

	if (patient1.birthdate.year > patient2.birthdate.year) return 1;

	else if (patient1.birthdate.year == patient2.birthdate.year)
	{
		if (patient1.birthdate.month > patient2.birthdate.month) return 1;

		else if (patient1.birthdate.month == patient2.birthdate.month) {

			if (patient1.birthdate.day > patient2.birthdate.day) return 1;
		}
	}

	return -1;
}

void sortByHospital(PtList patients) {
	int size;
	listSize(patients, &size);

	ListElem patient1, patient2;


	for (int i = 0; i < size; i++) {
		int indexMin = i;
		for (int j = i; j < size; j++) {
			listGet(patients, indexMin, &patient1);
			listGet(patients, j, &patient2);

			int result = compareHospital(patient1, patient2);

			if (result > 0) indexMin = j;

			if (result == 0) {
				//desempate pela data de nascimento
				int resultBirthdate = compareBirthdate(patient1, patient2);

				//Birthdate 2 é menor Birthdate 1
				if (resultBirthdate > 0) indexMin = j;
			}
		}
		swapPatients(patients, indexMin, i, patient1, patient2);
	}
}

int compareHospital(ListElem patient1, ListElem patient2) {
	//Return -1 se o Hospital 1 é menor que Hospital 2
	//Return  1 se o Hospital 2 é menor que Hospital 1

	int result_strcmp = strcmp(patient1.hospital, patient2.hospital);
	if (result_strcmp < 0) {
		//Hospital 1 é menor Hospital 2
		return -1;
	}
	else if (result_strcmp > 0) {
		//Hospital 2 é menor Hospital 1
		return 1;
	}
	else if (result_strcmp == 0) {
		//Hospital 1 é igual Hospital 2
		return 0;
	}
}

void sortByDistrict(PtList patients) {
	int size;
	listSize(patients, &size);
	ListElem patient1, patient2;

	for (int i = 0; i < size; i++) {
		int indexMin = i;
		for (int j = i; j < size; j++) {
			listGet(patients, indexMin, &patient1);
			listGet(patients, j, &patient2);

			int result = compareDistrict(patient1, patient2);

			if (result > 0) indexMin = j;

			if (result == 0) {
				//desempate pelo hospital
				int resultHospital = compareHospital(patient1, patient2);

				//Hospital 2 é menor Hospital 1
				if (resultHospital > 0) indexMin = j;
			}
		}
		swapPatients(patients, indexMin, i, patient1, patient2);
	}
}

int compareDistrict(ListElem patient1, ListElem patient2) {
	//Return -1 se o District 1 é menor que District 2
	//Return  1 se o District 2 é menor que District 1

	int result_strcmp = strcmp(patient1.district, patient2.district);
	if (result_strcmp < 0) {
		//District 1 é menor District 2
		return -1;
	}
	else if (result_strcmp > 0) {
		//District 2 é menor District 1
		return 1;
	}
	else if (result_strcmp == 0) {
		//District 1 é igual District 2
		return 0;
	}
}

void swapPatients(PtList patients, int rank1, int rank2, ListElem patient1, ListElem patient2) {
	ListElem temp;

	listSet(patients, rank2, patient1, &patient2);
	listSet(patients, rank1, patient2, &temp);
}

PtList copyData(PtList list) {
	int size;
	listSize(list, &size);
	PtList newList = listCreate(size);
	ListElem patient;
	for (int i = 0; i < size; i++) {
		listGet(list, i, &patient);
		listAdd(newList, i, patient);
	}
	return newList;
}