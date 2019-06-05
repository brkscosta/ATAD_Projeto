#pragma once
#include "date.h"
#include "clinicalData.h"

typedef char String[255];

typedef struct patient {
	int id;						/* Número que identifica um paciente */
	Date birthdate;				/* Data de nascimento*/
	char gender;				/* Género (M ou F)*/
	String hospital;			/* Nome do hospital de referencia do paciente*/
	String district;			/* Distrito onde pertence o hospital*/
	ClinicalData clinicalData;	/* Dados clínicos do doente (médias)*/
} Patient;

typedef Patient * PtPatient;

Patient patientCreate(int id, Date birthdate, char gender, String hospital, String district, ClinicalData  clinicalData);
int addClinicalDataToPatient(PtPatient patient, ClinicalData clinicalData);
void patientPrint(Patient patient);