//Excercise 4 - obligatory - must be submitted in its first version before 9/10 and OK'ed by me
//before 16/10.
//
//On http://bradconte.com/md5_c you will find an C implementation of the MD5-algorith.
//The code you'll find here does also include an example on how to use it. Test the code
//and the example (use the makefile from leksjon2.zip that allows for more than one
//        source file in a program).
//
//Then make a small program that does the following:
//
//        md5 -add <filename> 	- Calculate the MD5 checksum of the file (named filename) and
//        add it as a binary blob at the end of the file.
//
//md5 -test <filename>	- Calculate the MD5 checksum of the file and test if the checksum
//at the end of the file is the correct one.
//
//md5 -strip <filename>	- Same as test, but strip off the checksum at the end of the file.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include "md5.c"

bool validationIsGood(int iArgc, char *iArgv[], char *command);

bool addChecksumToFile(char *filename, char *checksum);

bool removeChecksumFromFile(char *filename, char *checksum);

bool checkIfChecksumInEndOfFile();

MD5_CTX calculateMD5Checksum(char *filename, MD5_CTX *ctx);

bool stripMD5ChecksumFromFile(FILE file);


int main(int iArgc, char *iArgv[]) {

    printf("Program started.\n");


    char *command = malloc(6 * sizeof(char));   // Definerer peker til kommando


    printf("Allocated memory for the *command\n");

    if (validationIsGood(iArgc, iArgv, *command)) {
        strcpy(command, iArgv[1]);
        printf("Command is: %s\n", command);

        char *filename = malloc(sizeof(iArgv[2]));
        *filename = (char)iArgv[2];

        printf("Filnavnet er: %s", filename);

        // Lager MD5-objekt
        MD5_CTX *ctx = NULL;
        *ctx = calculateMD5Checksum(filename, ctx);

        if (strcmp(command, "-add") == 0) {
            printf("-add command was executed. \n");


        } else if (strcmp(command, "-test") == 0) {
            printf("-test command was executed. \n");


        } else if (strcmp(command, "-strip") == 0) {
            printf("-strip command was executed. \n");

        }

        // Ingen else, for sikkerhets skyld.

        free(filename);   //Fjerner filename fra heap
    }


    free(command);        // Fjerner command fra heap

    return 0;
}

bool validationIsGood(int iArgc, char *iArgv[], char *command) {

    printf("Gikk inn i validationIsGood-metoden\n");
    printf("iArgv[1] er: %s \n", iArgv[1]);
    printf("size of command is: %d \n", (int) sizeof(command));

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

bool addChecksumToFile(char *filename, char *checksum) {
    FILE *fp = NULL;                    // Deklarerer filåpner
    fp = fopen(filename, "a");          // Bruker append

    fprintf(fp, "%s", checksum);        // Skriver MD5 checksum til fil
    fclose(fp);                         // Lukker fil
}

bool removeChecksumFromFile(char *filename, char *checksum) {}

bool checkIfChecksumInEndOfFile() {

}

MD5_CTX calculateMD5Checksum(char *filename, MD5_CTX *ctx) {
    printf("Gikk inn i calculateMD5Checksum-metoden \n");
    md5_init(ctx);
    FILE *fr = NULL;
    long size = 0;
    char *buffer;

    printf("Har deklarert alle metodene i calculateMD5Checksum-metoden \n");

    fr = fopen(filename, "rb");
    fseek(fr, 0, SEEK_END);     // Søk til slutten av filen
    size = ftell(fr);           // Få filpekerens verdi
    fseek(fr, 0, SEEK_SET);     // Søk tilbake til starten av filen
    printf("Har åpnet filen %s og funnet størrelsen på filen(%ld) \n", filename, size);

    ulong unsignedSize = (ulong) size;   // Gjør om long til unsigned long
    printf("Konvertert size(%ld) om til unsignedSize(%lu) \n", size, unsignedSize);

    buffer = (char *) malloc((size + 1) * sizeof(char)); // Allokerer nok minne for filen og \0
    fread(buffer, unsignedSize, 1, fr);             // Legger inn filen i det allokerte minnet

    md5_update(ctx, *buffer, unsignedSize);         // Lager Hash av fil
    printf("Har lagt til hash i ctx med MD5_update-metoden \n");

    fclose(fr);
    free(buffer);

    printf("Har lukket fil og frigjort minne for buffer. \n");
    return *ctx;

}

bool stripMD5ChecksumFromFile(FILE file) {

}




