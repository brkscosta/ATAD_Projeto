#pragma once

#include "list.h"

//FUNCOES AUXILIARES

void clrscr();
char** split(char* str, int nFields, const char *delim);

/*
Devolve a idade do paciente
Recebe:
data de nascimento e a data da consulta
Retorno:
Idade
*/
float getAge(Date date1, Date date2);


/*
Devolve o rank do paciente
Recebe:
lista de pacientes e o ID do paciente
Retorno:
Rank
*/
int findPatientRankById(PtList *patient, int patientId);

/*
Calcular valor medio
Recebe:
avg é a media com n elementos, o v é o novo elemento, e o n a posição
Retorno:
Valor medio
*/
float updateClinicalData(float avg, float v, int n);

void sortByBirthdate(PtList patients, int size);
int compareBirthdate(ListElem patient1, ListElem patient2);

void sortByHospital(PtList patients, int size);
int compareHospital(ListElem patient1, ListElem patient2);


void sortByDistrict(PtList patients, int size);
int compareDistrict(ListElem patient1, ListElem patient2);

void swapPatients(PtList patients, int rank, int rank2, ListElem patient, ListElem patient2);

//FUNCOES DO PROJETO
void load(PtList *patient);
void loadt(PtList *patient);
void show(PtList patients);
void clear(PtList patients);
void sort(PtList *patients);



