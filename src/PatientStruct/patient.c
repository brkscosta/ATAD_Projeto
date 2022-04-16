#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

PatientModel Patient(int id, Date birthdate, char gender, char *hospital, char *district)
{
    PatientModel newPatient;
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

    newClinicalData.c1 = 0;
    newClinicalData.c2 = 0;
    newClinicalData.c3 = 0;
    newClinicalData.c4 = 0;

    newPatient.clinicalData = newClinicalData;

    return newPatient;

}

void patientPrint(PatientModel patient) {
    printf("%3d %02d/%02d/%02d %c %-35s  %-16s    %2.0f %8.4f %6.1f %8.4f %10.4f \n",
        patient.id,
        patient.birthdate.day, patient.birthdate.month, patient.birthdate.year,
        patient.gender,
        patient.hospital,
        patient.district,
        patient.clinicalData.age,
        patient.clinicalData.bmi,
        patient.clinicalData.glucose,
        patient.clinicalData.insulin,
        patient.clinicalData.mcp1);
}

void patientNormPrint(PatientModel patient) {
    printf("%3d   %5.2f %5.2f  %5.2f    %5.2f    %5.2f \n",
        patient.id,
        patient.clinicalData.age,
        patient.clinicalData.bmi,
        patient.clinicalData.glucose,
        patient.clinicalData.insulin,
        patient.clinicalData.mcp1);
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
    printf("%5.1f  %8.4f   %3.0f    %8.4f  %10.4f\n",
        clinicalDataStats->avgAge,
        clinicalDataStats->avgBmi,
        clinicalDataStats->avgGlucose,
        clinicalDataStats->avgInsulin,
        clinicalDataStats->avgMcp1);
}


