//
// Created by bragalund on 12.10.17.
//



#include "FileWriter.h"
#include "FileReader.h"
#include "main.h"


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

void getLastPartOfFile(char *filename, char *lastPartOfFile){
    FILE *fr;
    fr = fopen(filename, "r");

    static const long max_len = 32 + 1;

    char buf[max_len + 1];
/* now read that many bytes from the end of the file */
    fseek(fr, -max_len, SEEK_END);
    ssize_t len = fread( buf, max_len, 1, fr);
    fclose(fr);
/* don't forget the nul terminator */
    buf[len] = '\0';

    // fseek(fr, 0, SEEK_SET);     //Setter pekeren til filen til starten av filen

/* and find the last newline character (there must be one, right?) */
    char *last_newline = strrchr(buf, '\n');
    char *lastLine = last_newline+1;
    strcpy(lastPartOfFile, lastLine);
    printf("last_newline: %s \n", last_newline);
    //printf("last_line: %s \n", lastPartOfFile);
}