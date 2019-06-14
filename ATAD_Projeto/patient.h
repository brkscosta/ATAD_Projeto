#pragma once

#include "date.h"

#define DOENCA1 1
#define DOENCA2 2
#define DOENCA3 3
#define SEM_DOENCA 4

typedef char String[255];


typedef struct clinicalData {
	float age;				/* M�dia da idade em anos quando os dados foram obtidos */
	float bmi;				/* Valores m�dios do Imc- Indice Massa corporal m�dio (Kg/m2) */
	float glucose;			/* Valores m�dios da Glicose (mg/dl) */
	float insulin;			/* Valores m�dios da Insulina (�U/ml) */
	float mcp1;				/* Valores m�dios da Proteina MCP-1 (pg/ml)*/
	int disease_type;		/* Classificacao do Doente
								1 � Doen�a1
								2 � Doen�a2
								3 � Doen�a3
								4 � Sem Doen�a
								Usado apenas na opcao NEURALNET*/
	int clinicalDataCount;	/* Numero de vezes que os dados foram obtidos*/

} ClinicalData;


typedef struct patient {
	int id;						/* N�mero que identifica um paciente */
	Date birthdate;				/* Data de nascimento*/
	char gender;				/* G�nero (M ou F)*/
	String hospital;			/* Nome do hospital de referencia do paciente*/
	String district;			/* Distrito onde pertence o hospital*/
	ClinicalData clinicalData;	/* Dados cl�nicos do doente (m�dias)*/
} Patient;

typedef struct clinicalataStatistics {
	float avgAge;				/* M�dia da idade em anos quando os dados foram obtidos */
	float avgBmi;				/* Valores m�dios do Imc- Indice Massa corporal m�dio (Kg/m2) */
	float avgGlucose;			/* Valores m�dios da Glicose (mg/dl) */
	float avgInsulin;			/* Valores m�dios da Insulina (�U/ml) */
	float avgMcp1;				/* Valores m�dios da Proteina MCP-1 (pg/ml)*/
	int patientCount;		/* Numero de vezes que os dados foram obtidos*/
}ClinicalDataStats;

typedef struct clinicalData *PtClinicalData;

typedef struct patient * PtPatient;

typedef struct clinicalDataStatistics * PtClinicalDataStatistics;

Patient patientCreate(int id, Date birthdate, char gender, char *hospital, char *district);
void patientPrint(Patient patient);

ClinicalDataStats ClinicalDataStatsCreate();

void ClinicalDataStatsPrint(ClinicalDataStats *ClinicalDataStat);