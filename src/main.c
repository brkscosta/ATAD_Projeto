﻿/* PROJETO  ATAD 2018-19
*   Identificacao dos Alunos:
*
*   Numero: 180221109 | Nome: Joanã Costa
*   Numero: 180221070 | Nome: Rafael Trindade
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "Utils/util.h"
#include "DataStructures/list.h"

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char const str2[]);
void printCommandsMenu();

int main() {

    PtList listPatients = listCreate(500);

    String command;
    int quit = 0;

    setlocale(LC_ALL, "PT");
    while (!quit) {
        printCommandsMenu();
        fgets(command, sizeof(command), stdin);

        /* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
        * string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
        command[strlen(command) - 1] = '\0';

        if (equalsStringIgnoreCase(command, "QUIT")) {
            quit = 1;
        }
        else if (equalsStringIgnoreCase(command, "LOAD")) {
            load(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "CLEAR")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else clear(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "SHOW")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else show(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "SORT")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else sort(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "AVG")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else avg(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "NORM")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else norm(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "QUEUE")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else queue(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "CHECKDISTRICT")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else checkDistrict(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "LOADT")) {
            loadt(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "NORMT")) {
            if (listIsEmpty(listPatients) == 1) {
                clrscr();
                printf("\033[0;31m Unloaded data\n");
                printf("\033[0m");
            }
            else normt(listPatients);
        }
        else if (equalsStringIgnoreCase(command, "NEURALNET")) {
            printf("Comando NEURALNET nao implementado.\n");
        }
        else {
            clrscr();
            printf("\033[0;31m Command not found.\n");
            printf("\033[0m");
        }
    }

    /* libertar memória e apresentar mensagem de saída. */
    listDestroy(&listPatients);
    return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char const str2[]) {
    /* Apenas faz uma comparacao utilizando o strcmp.
    * Necessita de modificacao para obter uma comparacao
    * 'case insensitive' */
    return (strcmp(str1, str2) == 0);
}

void printCommandsMenu() {
    printf("\n===================================================================================");
    printf("\n                          PROJECT: Patients and Clinical Data                      ");
    printf("\n===================================================================================");
    printf("\nA. Info about patients (LOAD, SHOW, CLEAR).");
    printf("\nB. Aggregated info about patients and clinical data (SORT, AVG, NORM, QUEUE, CHECKDISTRICT).");
    printf("\nC. Advanced indicator (LOADT, NORMT, NEURALNET)");
    printf("\nD. Exit (QUIT)\n\n");
    printf("COMMAND> ");
}
