
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

int findPatientRankById(PtList patient, int patientId) {
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

void load(PtList patients) {
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
        printf("\n\nImport patient file (file name): ");
        fgets(filename, sizeof(filename), stdin);

        filename[strlen(filename) - 1] = '\0';

        if (strcmp(filename, "BACK") == 0) { clrscr();  return; }

        error = fopen_s(&fPatient, "D:\\Git\\ATAD_Projeto\\src\\Resources\\patients.csv", "r"); 
        //error = fopen_s(&fPatient, filename, "r");
        if (error != 0) {
            printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
            printf("\033[0m");
        }
    } while (error != 0);

    do {
        printf("\n\nImport Clinical Data file (file name): ");
        fgets(filename, sizeof(filename), stdin);

        filename[strlen(filename) - 1] = '\0';

        if (strcmp(filename, "BACK") == 0) { clrscr();  return; }

        error = fopen_s(&fClinicalData, "D:\\Git\\ATAD_Projeto\\src\\Resources\\clinicalData.csv", "r");
        //error = fopen_s(&fClinicalData, filename, "r");
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
        listAdd(patients, countPatient, patient);
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


        rank = findPatientRankById(patients, atoi(tokens[0]));

        if (rank != -1) {
            //Caso o rank seja valido atualiza os dados clinicos

            listGet(patients, rank, &patientElem);

            int day, month, year;
            sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
            Date data2 = dateCreate(day, month, year);

            float age = getAge(patientElem.birthdate, data2);
            patientElem.clinicalData.age = calculateAVG(patientElem.clinicalData.age, age, patientElem.clinicalData.clinicalDataCount);

            patientElem.clinicalData.bmi = calculateAVG(patientElem.clinicalData.bmi, atof(tokens[2]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.glucose = calculateAVG(patientElem.clinicalData.glucose, atof(tokens[3]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.insulin = calculateAVG(patientElem.clinicalData.insulin, atof(tokens[4]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.mcp1 = calculateAVG(patientElem.clinicalData.mcp1, atof(tokens[5]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.clinicalDataCount++;
            listSet(patients, rank, patientElem, &oldClinicalData);

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

void loadt(PtList patients) {
    clrscr();
    printf("\n===================================================================================");
    printf("\n                          LOADT                                                    ");
    printf("\n===================================================================================\n");

    FILE* fPatient_train;
    int error = 0;
    char filename[30];

    printf(" \033[1;33mCommand \"BACK\" to return to the home menu \n");
    printf("\033[0m");

    do {
        printf("\n\nImport patient file (file name): ");
        fgets(filename, sizeof(filename), stdin);

        filename[strlen(filename) - 1] = '\0';

        if (strcmp(filename, "BACK") == 0) { clrscr();  return; }

        error = fopen_s(&fPatient_train, "patients_train.csv", "r");
        //error = fopen_s(&fPatient_train, filename, "r");
        if (error != 0) {
            printf("\n\n \033[0;31m An error occurred... It was not possible to open the file %s ...\n", filename);
            printf("\033[0m");
        }
    } while (error != 0);
    FILE* fClinicalData_train;
    do {
        printf("\n\nImport Clinical Data file (file name): ");
        fgets(filename, sizeof(filename), stdin);
        
        filename[strlen(filename) - 1] = '\0';

        if (strcmp(filename, "BACK") == 0) { clrscr();  return; }

        //error = fopen_s(&fClinicalData_train, "clinicalData_train.csv", "r");
        error = fopen_s(&fClinicalData_train, filename, "r");
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
        listAdd(patients, countPatient, patient);
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


        rank = findPatientRankById(patients, atoi(tokens[0]));

        if (rank != -1) {
            //Caso o rank seja valido atualiza os dados clinicos

            listGet(patients, rank, &patientElem);

            int day, month, year;
            sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
            Date data2 = dateCreate(day, month, year);

            float age = getAge(patientElem.birthdate, data2);
            patientElem.clinicalData.age = calculateAVG(patientElem.clinicalData.age, age, patientElem.clinicalData.clinicalDataCount);

            patientElem.clinicalData.bmi = calculateAVG(patientElem.clinicalData.bmi, atof(tokens[2]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.glucose = calculateAVG(patientElem.clinicalData.glucose, atof(tokens[3]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.insulin = calculateAVG(patientElem.clinicalData.insulin, atof(tokens[4]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.mcp1 = calculateAVG(patientElem.clinicalData.mcp1, atof(tokens[5]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.disease_type = atoi(tokens[6]);

            patientElem.clinicalData.c1 = calculateAVG(patientElem.clinicalData.c1, atof(tokens[7]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.c2 = calculateAVG(patientElem.clinicalData.c2, atof(tokens[8]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.c3 = calculateAVG(patientElem.clinicalData.c3, atof(tokens[9]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.c4 = calculateAVG(patientElem.clinicalData.c4, atof(tokens[10]), patientElem.clinicalData.clinicalDataCount);
            patientElem.clinicalData.clinicalDataCount += 1;

            listSet(patients, rank, patientElem, &oldClinicalData);
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

void sort(PtList patients) {
    clrscr();
    char command[20];
    int option;
    int quit = 0;

    printf("\n===================================================================================");
    printf("\n                          SORT                                                     ");
    printf("\n===================================================================================\n\n");
    printf("Select sorting criteria\n");
    printf("1- Birthdate\n");
    printf("2- Hospital\n");
    printf("3- District\n");
    printf("4- To return to the home menu\n\n");

    PtList auxiliar = copyPtList(patients);

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
            system("pause");
            listDestroy(&auxiliar);
            clrscr();
            return;
        }
        else {
            printf("\033[0;31m Command not found.\n");
            printf("\033[0m");
        }
    } while (quit != 1);
    listPrint(auxiliar);
    system("pause");
    listDestroy(&auxiliar);
    clrscr();

}

void avg(PtList patients) {
    clrscr();
    printf("\n===================================================================================");
    printf("\n                             AVG                                                   ");
    printf("\n===================================================================================\n\n");

    int size;
    listSize(patients, &size);

    PtList auxiliar = listCreate(size);
    auxiliar = copyPtList(patients);

    sortByDistrict(auxiliar);
    PtMap map = mapCreate(490);
    averageClinicalData(auxiliar, &map);

    mapPrint(map);
    system("pause");
    clrscr();
    mapDestroy(&map);

}

void averageClinicalData(PtList patients, PtMap *map) {
    int size;
    listSize(patients, &size);

    ListElem patient;
    ClinicalDataStats clinicalDataStats;
    String key;
    int count = 0;

    for (int i = 0; i < size; i++) {
        listGet(patients, i, &patient);
        strcpy_s(key, sizeof(key), patient.district);

        if (!mapContains(*map, key)) {
            clinicalDataStats = clinicalDataStatsCreate();
            clinicalDataStats.avgAge = calculateAVG(clinicalDataStats.avgAge, patient.clinicalData.age, clinicalDataStats.patientCount);
            clinicalDataStats.avgBmi = calculateAVG(clinicalDataStats.avgBmi, patient.clinicalData.bmi, clinicalDataStats.patientCount);
            clinicalDataStats.avgGlucose = calculateAVG(clinicalDataStats.avgGlucose, patient.clinicalData.glucose, clinicalDataStats.patientCount);
            clinicalDataStats.avgInsulin = calculateAVG(clinicalDataStats.avgInsulin, patient.clinicalData.insulin, clinicalDataStats.patientCount);
            clinicalDataStats.avgMcp1 = calculateAVG(clinicalDataStats.avgMcp1, patient.clinicalData.mcp1, clinicalDataStats.patientCount);
            clinicalDataStats.patientCount += 1;
            mapPut(*map, key, clinicalDataStats);
        }
        else {
            MapValue value; // == clinicalDataStats
            mapGet(*map, key, &value);
            value.avgAge = calculateAVG(value.avgAge, patient.clinicalData.age, value.patientCount);
            value.avgBmi = calculateAVG(value.avgBmi, patient.clinicalData.bmi, value.patientCount);
            value.avgGlucose = calculateAVG(value.avgGlucose, patient.clinicalData.glucose, value.patientCount);
            value.avgInsulin = calculateAVG(value.avgInsulin, patient.clinicalData.insulin, value.patientCount);
            value.avgMcp1 = calculateAVG(value.avgMcp1, patient.clinicalData.mcp1, value.patientCount);
            value.patientCount += 1;
            mapPut(*map, key, value);
        }
    }
}

void checkDistrict(PtList patients) {

    clrscr();
    char command[20];
    int quit = 0;
    int size;
    printf("\n===================================================================================");
    printf("\n                             CHECKDISTRICT                                         ");
    printf("\n===================================================================================\n");


    listSize(patients, &size);

    PtMap map = mapCreate(size);
    averageClinicalData(patients, &map);
    MapValue value;

    do {
        printf("\nDISTRICT> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (mapContains(map, command) == 1) {
            mapGet(map, command, &value);
            printf("District              Age    BMI       Glucose Insulina  MCP1\n");
            mapKeyPrint(command);
            mapValuePrint(value);
        }
        else if (strcmp(command, " ") == 0 || strcmp(command, "") == 0) {
            quit = 1;
            mapDestroy(&map);
            system("pause");
            clrscr();
            return;
        }
        else {
            printf("\033[0;31m District not found.\n");
            printf("\033[0m");
        }

    } while (quit != 1);

    mapPrint(map);
    mapDestroy(&map);
    system("pause");
    clrscr();
}

void queue(PtList patients) {

    clrscr();
    char command[20];
    int quit = 0;
    int size, size1;
    printf("\n===================================================================================");
    printf("\n                             QUEUE                                                  ");
    printf("\n===================================================================================\n");


    PtQueue queuePatients = queueCreate(500);

    ClinicalDataStats min = clinicalDataStatsCreate(), max = clinicalDataStatsCreate(), averageValue = clinicalDataStatsCreate();
    findMinAndMaxAndAVG(patients, &min, &max, &averageValue);

    addToQueue(patients, &queuePatients, &averageValue);

    printf("Available commands: NEXT & STOP\n");
    do {

        printf("COMMAND> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "NEXT") == 0) {
            if (queueIsEmpty(queuePatients) == 1) {
                printf("Queue is empty");
                system("pause");
                quit = 1;
            }
            ListElem queueElem;
            queuePeek(queuePatients, &queueElem);
            printf("          Indice BirthDate Sex Hospital                             District           Age  Bmi     Glicose Insulin  Mcp1\n\n");
            queueElemPrint(queueElem);
            queueDequeue(queuePatients, &queueElem);
        }
        else if (strcmp(command, "STOP") == 0) {
            quit = 1;
        }
        else {
            printf("\033[0;31m Command not found.\n");
            printf("\033[0m");
        }

    } while (quit != 1);
    system("pause");
    queueDestroy(&queuePatients);
    clrscr();
}

void norm(PtList patients) {
    char command[20];
    int k;
    int quit = 0;
    clrscr();
    printf("\n===================================================================================");
    printf("\n                             NORM                                                  ");
    printf("\n===================================================================================\n\n");
    int size;
    listSize(patients, &size);
    PtList auxiliar = listCreate(size);
    auxiliar = copyPtList(patients);

    printf(" \033[1;33mCommand \"BACK\" to return to the home menu \n");
    printf("\033[0m");
    printf("Enter the value of K(int)\n");

    do {
        printf("K> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';
        k = atoi(command);

        if (k > 0) {
            normalizeClinicalData(auxiliar, k);
            listNormPrint(auxiliar);
            quit = 1;
        } else if (strcmp(command, "BACK") == 0)
        {
            quit = 1;
        } else {
            printf("\033[0;31m Is not a digit\n", k);
            printf("\033[0m");
        }
    } while (quit != 1);

    printf("\n");
    system("pause");
    listDestroy(&auxiliar);
    clrscr();
}

void normt(PtList patients) {
    clrscr();
    printf("\n===================================================================================");
    printf("\n                             NORMT                                                  ");
    printf("\n===================================================================================\n\n");
    int size;
    listSize(patients, &size);
    PtList auxiliar = listCreate(size);
    auxiliar = copyPtList(patients);
    normalizeClinicalData(auxiliar, 5);
    listNormPrint(auxiliar);
    printf("\n");
    system("pause");
    listDestroy(&auxiliar);
    clrscr();
}

PtList normalizeClinicalData(PtList patients, int k) {

    int size;
    ListElem elem, oldElem;

    listSize(patients, &size);

    ClinicalDataStats min = clinicalDataStatsCreate(), max = clinicalDataStatsCreate(), averageValue = clinicalDataStatsCreate();
    findMinAndMaxAndAVG(patients, &min, &max, &averageValue);

    for (int i = 0; i < size; i++) {
        listGet(patients, i, &elem);
        elem.clinicalData.age = calculateNorm(elem.clinicalData.age, min.avgAge, max.avgAge, k);
        elem.clinicalData.bmi = calculateNorm(elem.clinicalData.bmi, min.avgBmi, max.avgBmi, k);
        elem.clinicalData.glucose = calculateNorm(elem.clinicalData.glucose, min.avgGlucose, max.avgGlucose, k);
        elem.clinicalData.insulin = calculateNorm(elem.clinicalData.insulin, min.avgInsulin, max.avgInsulin, k);
        elem.clinicalData.mcp1 = calculateNorm(elem.clinicalData.mcp1, min.avgMcp1, max.avgMcp1, k);
        listSet(patients, i, elem, &oldElem);
    }
    return patients;
}

void clrscr() {
    system("@cls||clear");
}

char** split(char *string, int nFields, const char *delim) {

    char **tokens = (char**)malloc(sizeof(char*) * nFields);

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
    else if (date1.month == date2.month)
    {
        if (date2.day < date1.day) return age - 1;
    }

    return age;
}

float calculateAVG(float avg, float v, int n) {
    float value;

    value = ((avg * n) + v) / (n + 1);

    return value;
}


void sortByBirthdate(PtList patients) {
    int size;
    listSize(patients, &size);
    ListElem patient1, patient2;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            listGet(patients, j, &patient1);
            listGet(patients, (j + 1), &patient2);

            int result = compareBirthdate(patient1, patient2);
            if (result == 1) {
                swapPatients(patients, j, (j + 1), patient1, patient2);
            }
        }
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
        for (int j = 0; j < size - i - 1; j++) {

            listGet(patients, j, &patient1);
            listGet(patients, (j + 1), &patient2);

            int result = compareHospital(patient1, patient2);
            if (result > 0) {
                swapPatients(patients, j, (j + 1), patient1, patient2);
            }
            else if (result == 0) {
                //desempate pela data de nascimento
                int resultBirthdate = compareBirthdate(patient1, patient2);

                //Birthdate 2 é menor Birthdate 1
                if (resultBirthdate > 0) swapPatients(patients, j, (j + 1), patient1, patient2);
            }
        }
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
    return 0;
}

void sortByDistrict(PtList patients) {
    int size;
    listSize(patients, &size);
    ListElem patient1, patient2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            listGet(patients, j, &patient1);
            listGet(patients, (j + 1), &patient2);

            int result = compareDistrict(patient1, patient2);
            if (result > 0) {
                swapPatients(patients, j, (j + 1), patient1, patient2);
            }
            else if (result == 0) {
                //desempate pelo hospital
                int resultHospital = compareHospital(patient1, patient2);

                //Hospital 2 é menor Hospital 1
                if (resultHospital > 0)  swapPatients(patients, j, (j + 1), patient1, patient2);
            }
        }
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
    return 0;
}

void swapPatients(PtList patients, int rank1, int rank2, ListElem patient1, ListElem patient2) {
    ListElem temp;

    listSet(patients, rank2, patient1, &patient2);
    listSet(patients, rank1, patient2, &temp);
}

PtList copyPtList(PtList list) {
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

void addToQueue(PtList list, PtQueue *queue, PtClinicalDataStats averageValue) {

    int size;
    listSize(list, &size);
    ListElem patientList;
    int count = 0;

    for (int i = 0; i < size; i++) {
        listGet(list, i, &patientList);
        if (patientList.clinicalData.age < averageValue->avgAge) {
            queueEnqueue(*queue, patientList);
            count++;
        }
        else if (patientList.clinicalData.age >= averageValue->avgAge) {

            if (patientList.clinicalData.bmi < averageValue->avgBmi &&
                patientList.clinicalData.glucose < averageValue->avgGlucose  &&
                patientList.clinicalData.insulin < averageValue->avgInsulin  &&
                patientList.clinicalData.mcp1 < averageValue->avgMcp1) {

                queueEnqueue(*queue, patientList);
                count++;
            }
        }

    }
    queuePrint(*queue);
    printf("\n%d elements were copied to queue!\n\n", count);
}

void findMinAndMaxAndAVG(PtList list, PtClinicalDataStats minValue, PtClinicalDataStats maxValue, PtClinicalDataStats averageValue) {
    int size;
    ListElem patient;
    listSize(list, &size);

    listGet(list, 0, &patient);
    minValue->avgAge = patient.clinicalData.age;
    minValue->avgBmi = patient.clinicalData.bmi;
    minValue->avgGlucose = patient.clinicalData.glucose;
    minValue->avgInsulin = patient.clinicalData.insulin;
    minValue->avgMcp1 = patient.clinicalData.mcp1;

    maxValue->avgAge = patient.clinicalData.age;
    maxValue->avgBmi = patient.clinicalData.bmi;
    maxValue->avgGlucose = patient.clinicalData.glucose;
    maxValue->avgInsulin = patient.clinicalData.insulin;
    maxValue->avgMcp1 = patient.clinicalData.mcp1;

    for (int i = 0; i < size; i++) {
        listGet(list, i, &patient);
        if (minValue->avgAge > patient.clinicalData.age) minValue->avgAge = patient.clinicalData.age;
        if (maxValue->avgAge < patient.clinicalData.age) maxValue->avgAge = patient.clinicalData.age;

        if (minValue->avgBmi > patient.clinicalData.bmi) minValue->avgBmi = patient.clinicalData.bmi;
        if (maxValue->avgBmi < patient.clinicalData.bmi) maxValue->avgBmi = patient.clinicalData.bmi;

        if (minValue->avgGlucose > patient.clinicalData.glucose) minValue->avgGlucose = patient.clinicalData.glucose;
        if (maxValue->avgGlucose < patient.clinicalData.glucose) maxValue->avgGlucose = patient.clinicalData.glucose;

        if (minValue->avgInsulin > patient.clinicalData.insulin) minValue->avgInsulin = patient.clinicalData.insulin;
        if (maxValue->avgInsulin < patient.clinicalData.insulin) maxValue->avgInsulin = patient.clinicalData.insulin;

        if (minValue->avgMcp1 > patient.clinicalData.mcp1) minValue->avgMcp1 = patient.clinicalData.mcp1;
        if (maxValue->avgMcp1 < patient.clinicalData.mcp1) maxValue->avgMcp1 = patient.clinicalData.mcp1;
    }

    averageValue->avgAge = (minValue->avgAge + maxValue->avgAge) / 2;
    averageValue->avgBmi = (minValue->avgBmi + maxValue->avgBmi) / 2;
    averageValue->avgGlucose = (minValue->avgGlucose + maxValue->avgGlucose) / 2;
    averageValue->avgInsulin = (minValue->avgInsulin + maxValue->avgInsulin) / 2;
    averageValue->avgMcp1 = (minValue->avgMcp1 + maxValue->avgMcp1) / 2;

}

float calculateNorm(float x, float min, float max, float k) {
    float value;

    value = ((x - min) / (max - min)) * 2 * k - k;
    return value;
}