#pragma once

#include "date.h"

#define DOENCA1 1
#define DOENCA2 2
#define DOENCA3 3
#define SEM_DOENCA 4

typedef char String[255];


typedef struct clinicalData {
	float age;				/* Média da idade em anos quando os dados foram obtidos */
	float bmi;				/* Valores médios do Imc- Indice Massa corporal médio (Kg/m2) */
	float glucose;			/* Valores médios da Glicose (mg/dl) */
	float insulin;			/* Valores médios da Insulina (µU/ml) */
	float mcp1;				/* Valores médios da Proteina MCP-1 (pg/ml)*/
	int disease_type;		/* Classificacao do Doente
								1 – Doença1
								2 – Doença2
								3 – Doença3
								4 – Sem Doença
								Usado apenas na opcao NEURALNET*/
	int clinicalDataCount;	/* Numero de vezes que os dados foram obtidos*/

} ClinicalData;


typedef struct patient {
	int id;						/* Número que identifica um paciente */
	Date birthdate;				/* Data de nascimento*/
	char gender;				/* Género (M ou F)*/
	String hospital;			/* Nome do hospital de referencia do paciente*/
	String district;			/* Distrito onde pertence o hospital*/
	ClinicalData clinicalData;	/* Dados clínicos do doente (médias)*/
} Patient;

typedef struct clinicalataStatistics {
	float avgAge;				/* Média da idade em anos quando os dados foram obtidos */
	float avgBmi;				/* Valores médios do Imc- Indice Massa corporal médio (Kg/m2) */
	float avgGlucose;			/* Valores médios da Glicose (mg/dl) */
	float avgInsulin;			/* Valores médios da Insulina (µU/ml) */
	float avgMcp1;				/* Valores médios da Proteina MCP-1 (pg/ml)*/
	int patientCount;		/* Numero de vezes que os dados foram obtidos*/
}ClinicalDataStats;

typedef struct clinicalData *PtClinicalData;

typedef struct patient * PtPatient;

typedef struct clinicalDataStatistics * PtClinicalDataStatistics;

Patient patientCreate(int id, Date birthdate, char gender, char *hospital, char *district);
void patientPrint(Patient patient);

ClinicalDataStats ClinicalDataStatsCreate();

void ClinicalDataStatsPrint(ClinicalDataStats *ClinicalDataStat);