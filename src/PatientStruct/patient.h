#pragma once

#include "../Utils/date.h"

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

	/* Usado apenas na opcao NEURALNET */
	float c1;
	float c2;
	float c3;
	float c4;

} ClinicalData;


typedef struct patient {
	int id;						/* N�mero que identifica um paciente */
	Date birthdate;				/* Data de nascimento*/
	char gender;				/* G�nero (M ou F)*/
	String hospital;			/* Nome do hospital de referencia do paciente*/
	String district;			/* Distrito onde pertence o hospital*/
	ClinicalData clinicalData;	/* Dados cl�nicos do doente (m�dias)*/
} Patient;

typedef struct ClinicalDataStats {
	float avgAge;				/* M�dia da idade em anos quando os dados foram obtidos */
	float avgBmi;				/* Valores m�dios do Imc- Indice Massa corporal m�dio (Kg/m2) */
	float avgGlucose;			/* Valores m�dios da Glicose (mg/dl) */
	float avgInsulin;			/* Valores m�dios da Insulina (�U/ml) */
	float avgMcp1;				/* Valores m�dios da Proteina MCP-1 (pg/ml)*/
	int patientCount;		/* Numero de vezes que os dados foram obtidos*/
}ClinicalDataStats;

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
Patient patientCreate(int id, Date birthdate, char gender, char *hospital, char *district);

/*
Mostra os dados do paciente
Recebe:
patient: Estrututa do tipo Paciente
Retorna:
 -------
*/
void patientPrint(Patient patient);

/*
Mostra os dados do paciente com a formata��o do norm
Recebe:
patient: Estrututa do tipo Paciente
Retorna:
 -------
*/
void patientNormPrint(Patient patient);
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