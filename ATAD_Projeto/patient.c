#include <stdio.h>
#include <stdlib.h>
#include "patient.h"


Patient patientCreate(int id, Date birthdate, char gender, char *hospital, char *district)
{
	Patient newPatient;
	newPatient.id = id;
	newPatient.birthdate = birthdate;
	newPatient.gender = gender;
	strcpy_s(newPatient.hospital, sizeof(newPatient.hospital), hospital);
	strcpy_s(newPatient.district, sizeof(newPatient.district), district);

	ClinicalData newClinicalData;
	newClinicalData.age = 0;
	newClinicalData.bmi = 0;
	newClinicalData.glucose = 0;
	newClinicalData.insulin = 0;
	newClinicalData.mcp1 = 0;
	newClinicalData.disease_type = 0;
	newClinicalData.clinicalDataCount = 0;

	newPatient.clinicalData = newClinicalData;

	return newPatient;

}

void patientPrint(Patient patient) {
	//printf("%3d \t %d-%d-%d \b %c \b %-35s \t %-15s %.2f \t %.2f \t %.2f \t %.2f \t %.2f \t",
	/*printf("%3d\t%d/%d/%d \t %c\t%-35s\t%s",
		patient.id,
		patient.birthdate.day, patient.birthdate.month, patient.birthdate.year,
		patient.gender,
		patient.hospital,
		patient.district);
	printf("\t\tClinical Data\n \t\tAge:%.1f\tBmi:%.2f\tGlicose:%.1f\tInsulin:%.1f\tMcp1:%.1f\n",
		patient.clinicalData.age,
		patient.clinicalData.bmi,
		patient.clinicalData.glucose,
		patient.clinicalData.insulin,
		patient.clinicalData.mcp1);*/

	printf("%3d    %02d/%02d/%02d    %c %-35s    %s    %.2f",
		patient.id,
		patient.birthdate.day, patient.birthdate.month, patient.birthdate.year,
		patient.gender,
		patient.hospital,
		patient.district, patient.clinicalData.age);
	/*printf("\t\tClinical Data\n \t\tAge:%.1f\tBmi:%.2f\tGlicose:%.1f\tInsulin:%.1f\tMcp1:%.1f\n",
		patient.clinicalData.age,
		patient.clinicalData.bmi,
		patient.clinicalData.glucose,
		patient.clinicalData.insulin,
		patient.clinicalData.mcp1);
*/

}

ClinicalDataStats clinicalDataStatsCreate() {

	ClinicalDataStats newClinicalDataStats;
	newClinicalDataStats.avgAge = 0;
	newClinicalDataStats.avgBmi = 0;
	newClinicalDataStats.avgGlucose = 0;
	newClinicalDataStats.avgInsulin = 0;
	newClinicalDataStats.avgMcp1 = 0;
	newClinicalDataStats.patientCount = 0;

	return newClinicalDataStats;
}


void clinicalDataStatsPrint(ClinicalDataStats *clinicalDataStats) {
	printf("%f\t %f\t %f\t %f\t %f \t %d\n", clinicalDataStats->avgAge, clinicalDataStats->avgBmi,
		clinicalDataStats->avgGlucose, clinicalDataStats->avgInsulin, clinicalDataStats->avgMcp1, clinicalDataStats->patientCount);
}

