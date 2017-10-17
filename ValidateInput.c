//
// Created by Henrik Bakkelund on 12.10.17.
//


#include "ValidateInput.h"

bool validationIsGood(int iArgc, char *iArgv[], char *command) {

    //Sjekker om kommando-input er større enn verdien til pekeren
    if (strlen(iArgv[1]) >= sizeof(command)) {
        printf("command %s is too long. \n", iArgv[1]);
        exit(1);
    }

    //Lager en generell error melding
    char *errorMessage;
    errorMessage = "USAGE: ./main -[command] <filename>\n"
            "Commands are: -add, -test, -strip\n";

    //Sjekker om det er tilstrekkelig med argumenter
    if (iArgc != 3) {
        printf("To few arguments.\n");
        printf("%s", errorMessage);
        exit(1);
    }

    //Sjekke om fil eksisterer
    FILE *file;
    if ((file = fopen(iArgv[2], "r"))) {
        fclose(file);
    } else {
        printf("File %s does not exist.\n", iArgv[2]);
        printf("%s", errorMessage);
        exit(1);
    }


    //Sjekker om kommandoen er lik en av de godtatte kommandoene
    if (strcmp(iArgv[1], "-add") == 0 || strcmp(iArgv[1], "-test") == 0 || strcmp(iArgv[1], "-strip") == 0) {
        return true;
    } else {
        printf("Wrong command. \n");
        printf("%s", errorMessage);
        exit(1);
    }

    // Metoden returnerer false som standard
    return false;
}