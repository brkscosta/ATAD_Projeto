#pragma once

#include "../DataStructures/list.h"
#include "../DataStructures/map.h"
#include "../DataStructures/queue.h"

//FUNCOES DO PROJETO
void load(PtList patient);
void loadt(PtList patient);
void show(PtList patients);
void clear(PtList patients);
void sort(PtList patients);
void avg(PtList patients);
void averageClinicalData(PtList patients, PtMap* map);
void checkDistrict(PtList patients);
void queue(PtList patients);
void norm(PtList patients);
void normt(PtList patients);
PtList normalizeClinicalData(PtList patients, int k);

//FUNCOES AUXILIARES

void clrscr();
char** split(char* str, int nFields, const char *delim);

/*
Devolve o rank do paciente
Recebe:
lista de pacientes e o ID do paciente
Retorno:
Rank
*/
int findPatientRankById(PtList patient, int patientId);

/*
Devolve a idade do paciente
Recebe:
Data de nascimento e a data da consulta
Retorno:
Idade
*/
float getAge(Date date1, Date date2);

/*
Copiar para uma instância do TAD Queue todos os pacientes que se enquadrem nos seguintes critérios
-A  sua  idade  seja  inferior  ao  valor  médio  do  intervalo  [min(age),  max(age)]  das idades de todos os pacientes.
ou
-A sua idade seja superior ao valor médio do intervalo [min(age),max(age)] das idades de todos os pacientes.
-O valor dos atributos bmi, glucose, insuline e mcp1 sejam inferiores
ao valor médio do intervalo entre o [min(atr),max(atr)] para cada um destes 4 atributros.
*/
void addToQueue(PtList list, PtQueue *queue, PtClinicalDataStats max);

/*
Calcular valor medio
Recebe:
avg é a media com n elementos, o v é o novo elemento, e o n a posição
Retorno:
Valor medio
*/
float calculateAVG(float avg, float v, int n);


/*
Ordena de forma crescente por data de nascimento
Recebe:
Lista de pacientes(patients)
*/
void sortByBirthdate(PtList patients);

/*
Compara datas de nascimento dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o data 1 é menor que data 2
 1 se o data 2 é menor que data 1
*/
int compareBirthdate(ListElem patient1, ListElem patient2);


/*
Ordena de forma crescente por Hospital
Em caso de desempate ordena pela data de nascimento
Recebe:
Lista de pacientes(patients)
*/
void sortByHospital(PtList patients);

/*
Compara hospitais dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o hospital 1 é menor que hospital 2
 1 se o hospital 2 é menor que hospital 1
 0 se o hospital 1 é igual que hospital 2
*/
int compareHospital(ListElem patient1, ListElem patient2);

/*
Ordena de forma crescente por Distrito
Em caso de desempate ordena por hospital
Recebe:
Lista de pacientes(patients)
*/
void sortByDistrict(PtList patients);

/*
Compara distritos dos 2 pacientes
Recebe:
2 pacientes patient1, patient2
Retorno:
-1 se o distrito 1 é menor que distrito 2
 1 se o distrito 2 é menor que distrito 1
 0 se o distrito 1 é igual que distrito 2
*/
int compareDistrict(ListElem patient1, ListElem patient2);

/*
Troca o rank, o paciente 1 com o paciente 2
Recebe:
Lista de pacientes(patients), paciente 1(patient1) e o seu rank (rank1), paciente 2(patient2) e o seu rank (rank2)
*/
void swapPatients(PtList patients, int rank1, int rank2, ListElem patient1, ListElem patient2);


/*
Copia os dados de uma lista para outra
*/
PtList copyPtList(PtList list);

/*
Procura na lista o valor medio minimo e maximo de cada atribuito Clinical Data
*/
void findMinAndMaxAndAVG(PtList list, PtClinicalDataStats minValue, PtClinicalDataStats maxValue, PtClinicalDataStats averageValue);


/*
Calculo da normalização
Recebe:
x o valor atual do atributo,
o min o valor medio minimo do atributo,
max o valor medio maximo do atributo e
k o valor introduzido pelo utilizador
Retorno:
valor normalizado
*/
float calculateNorm(float x, float min, float max, float k);


