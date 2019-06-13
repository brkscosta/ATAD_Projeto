﻿#pragma once

#include "list.h"


//FUNCOES DO PROJETO
void load(PtList *patient);
void loadt(PtList *patient);
void show(PtList patients);
void clear(PtList patients);
void sort(PtList *patients);


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
avg � a media com n elementos, o v � o novo elemento, e o n a posi��o
Retorno:
Valor medio
*/
float updateClinicalData(float avg, float v, int n);


/*
Ordena de forma crescente por data de nascimento
Recebe:
Lista de pacientes(patients), size da lista (size)
*/
void sortByBirthdate(PtList patients, int size);
/*
Compara datas de nascimento dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o data 1 � menor que data 2
 1 se o data 2 � menor que data 1
*/
int compareBirthdate(ListElem patient1, ListElem patient2);


/*
Ordena de forma crescente por Hospital
em caso de desempate ordena pela data de nascimento
Recebe:
Lista de pacientes(patients), size da lista (size)
*/
void sortByHospital(PtList patients, int size);

/*
Compara hospitais dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o hospital 1 � menor que hospital 2
 1 se o hospital 2 � menor que hospital 1
 0 se o hospital 1 � igual que hospital 2
*/
int compareHospital(ListElem patient1, ListElem patient2);


/*
Ordena de forma crescente por Distrito
em caso de desempate ordena por hospital
Recebe:
Lista de pacientes(patients), size da lista (size)
*/
void sortByDistrict(PtList patients, int size);

/*
Compara distritos dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o distrito 1 � menor que distrito 2
 1 se o distrito 2 � menor que distrito 1
 0 se o distrito 1 � igual que distrito 2
*/
int compareDistrict(ListElem patient1, ListElem patient2);

/*
Troca o rank, o paciente 1 com o paciente 2
Recebe:
Lista de pacientes(patients), paciente 1(patient1) e o seu rank (rank1), paciente 2(patient2) e o seu rank (rank2)
*/
void swapPatients(PtList patients, int rank1, int rank2, ListElem patient1, ListElem patient2);




