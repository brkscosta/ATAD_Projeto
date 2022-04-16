#pragma once

#include "../Utils/date.h"

#define DOENCA1 1
#define DOENCA2 2
#define DOENCA3 3
#define SEM_DOENCA 4

typedef char String[255];

typedef struct clinicalData {
    float age;        // Média da idade em anos quando os dados foram obtidos
    float bmi;        // Valores médios do Imc- Indice Massa corporal m�dio (Kg/m2)
    float glucose;    // Valores médios da Glicose (mg/dl)
    float insulin;    // Valores médios da Insulina (�U/ml)
    float mcp1;       // Valores médios da Proteina MCP-1 (pg/ml)
    int disease_type; // Classificacao do Doente
                               /* 1 Doença1
                                2 Doença2
                                3 Doença3
                                4 Sem Doença
                                  Usado apenas na opcao NEURALNET */
    int clinicalDataCount; // Número de vezes que os dados foram obtidos

    /* Usado apenas na opcao NEURALNET */
    float c1;
    float c2;
    float c3;
    float c4;

} ClinicalData;


typedef struct patient {
    int id;	                   // Número que identifica um paciente
    Date birthdate;            // Data de nascimento
    char gender;               // Gênero (M ou F)
    String hospital;           // Nome do hospital de referencia do paciente
    String district;           // Distrito onde pertence o hospital
    ClinicalData clinicalData; // Dados cl�nicos do doente (médias)
} PatientModel;

typedef struct ClinicalDataStats {
    float avgAge;     //Média da idade em anos quando os dados foram obtidos
    float avgBmi;     //Valores médios do Imc- Indice Massa corporal m�dio (Kg/m2)
    float avgGlucose; //Valores médios da Glicose (mg/dl)
    float avgInsulin; //Valores médios da Insulina (�U/ml)
    float avgMcp1;    //Valores médios da Proteina MCP-1 (pg/ml
    int patientCount; //Numero de vezes que os dados foram obtidos
} ClinicalDataStats;

typedef struct clinicalData *PtClinicalData;

typedef struct patient * PtPatient;

typedef struct ClinicalDataStats * PtClinicalDataStats;

/*
Construtor para o paciente
Recebe:
ID, Data Nascimento, Sexo, hospital, distrito
Retorna:
Paciente
*/
PatientModel Patient(int id, Date birthdate, char gender, char *hospital, char *district);

/*
Mostra os dados do paciente
Recebe:
patient: Estrututa do tipo Paciente
Retorna:
 -------
*/
void patientPrint(PatientModel patient);

/*
Mostra os dados do paciente com a formata��o do norm
Recebe:
patient: Estrututa do tipo Paciente
Retorna:
 -------
*/
void patientNormPrint(PatientModel patient);
/*
Construtor para os dados cl�nicos
Recebe:
A m�dia dos dados: Age, BMI, Glucose, Insulina, MCP1
Retorna:
Objeto das estat�scas dos dados cl�inicos
*/
ClinicalDataStats clinicalDataStatsCreate();


/*
Mostra a m�dia dos dados cl�nicos
Recebe:
Os dados cl�nicos
Retorna:
----------
*/
void clinicalDataStatsPrint(ClinicalDataStats *clinicalDataStats);