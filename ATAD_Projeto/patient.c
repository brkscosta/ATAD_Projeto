#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

Patient patientCreate(int id, Date birthdate, char gender, String hospital, String district, ClinicalData clinicalData)
{
	Patient newPatient;
	newPatient.id = id;
	newPatient.birthdate = birthdate;
	newPatient.gender = gender;
	strcpy_s(newPatient.hospital, 256, hospital);
	strcpy_s(newPatient.district, 256, district);
	//newPatient.clinicalData = clinicalData;
	return newPatient;

}

int addClinicalDataToPatient(PtPatient patient, ClinicalData clinicalData)
{
	return 0;
}

void patientPrint(Patient patient) {
	printf("ID: %d|Data de nascimento(dd/mm/yy): %d-%d-%d | Genero: %c | Hospital: %s | Distrito: %s |\n",
		patient.id,
		patient.birthdate.day, patient.birthdate.month, patient.birthdate.year,
		patient.gender, patient.hospital, patient.district);
	printf("Dados clinicos do doente(medias)");


	/*printf("Idade media: %d \n BMI: %f \n Glicose (mg/dl): %f \n Insulina (µU/ml): %f \n Proteina MCP-1 (pg/ml): %f \n  Classificacao do Doente: %d \n Nº Consultas: %d \n",
		patient.clinicalData.age, patient.clinicalData.bmi,
		patient.clinicalData.glucose, patient.clinicalData.insulin,
		patient.clinicalData.mcp1, patient.clinicalData.disease_type, patient.clinicalData.clinicalDataCount);*/

}


