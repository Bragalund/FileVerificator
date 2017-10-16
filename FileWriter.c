//
// Created by bragalund on 12.10.17.
//



#include "FileWriter.h"
#include "FileReader.h"


void printHashToFile(const BYTE *hash, FILE *file) {
    int i;
    fprintf(file, "\n");
    for (i = 0; i < 16; i++) {
        fprintf(file, "%02x", hash[i]);
    }
}

bool addChecksumToFile(char *filename, BYTE *checksum) {
    printf("Gikk inn i addChecksumToFile-metoden.\n");
    long getPreviousSize = getSizeOfFile(filename);  //Lagrer filstørrelsen for å kunne sjekke om den er annerledes etter å ha skrevet til filen
    FILE *fp;                                        // Deklarerer filåpner
    fp = fopen(filename, "a");                       // Bruker append på filen
    printf("getPreviousSize er: %ld \n", getPreviousSize);

    if (fp == NULL) {                                  //Sjekker om filen er NULL
        printf("fp var NULL i addChecksumToFile.\n");
        return false;
    }
    printHashToFile(checksum, fp);        // Skriver MD5 checksum til fil
    fclose(fp);                         // Lukker fil

    if (getSizeOfFile(filename) != getPreviousSize) { // sjekker om filstørrelsen har endret seg
        printf("filstørrelsen %ld er ikke lik %ld \n", getSizeOfFile(filename), getPreviousSize);
        return true;
    }
    return false;
}

