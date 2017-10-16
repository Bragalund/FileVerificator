//
// Created by bragalund on 12.10.17.
//

#include "Util.h"
#include "md5.h"
#include "main.h"
#include "FileReader.h"


BYTE *getChecksumOfString(char *chars, long amount) {
    // Lager MD5-objekt
    printf("Prøver å deklarerere *ctx \n");
    MD5_CTX *ctx = malloc(sizeof(MD5_CTX));
    md5_init(ctx);
    printf("Har initialisert ctx \n");
    if (!ctx) {   // Avslutter om ctx-objekt er NULL
        printf("ctx var NULL \n");
        exit(1);
    }
    printf("Har lagt filen inn i buffer.\n");

    md5_update(ctx, (const BYTE *) chars, amount);               // Lager Hash av fil
    printf("Har lagt til chars i ctx med MD5_update-metoden \n");
    BYTE *hashBytes = malloc(16 * sizeof(BYTE));
    md5_final(ctx, hashBytes);
    printf("Har allokert minne til hashBytes \n");
    printf("hashBytes: \n");
    printHash(hashBytes);
    free(ctx);
    return hashBytes;
}


void printHash(BYTE *hash) {
    int i;
    for (i = 0; i < 16; i++)
        printf("%02x", hash[i]);
    printf("\n");
}


// TODO lag denne metoden!
bool checkIfChecksumInEndOfFile(char *filename, char *lastPartOfFile) {

    printf("Entered checkIfChecksumInEndOfFile.\n");
    FILE *fr;
    fr = fopen(filename, "r");              // åpner fil for å bli lest
    long sizeOfHash = sizeof(lastPartOfFile)*4+1;     // finner størrelsen av hashen som er

    //Kalkuler egen hash fra resten av filen
    printf("Prøver å kalkulere egen hash basert på fil... \n");
    long sizeOfUnhashedFile = getSizeOfFile(filename) - sizeOfHash;

    char *buffer;
    buffer = (char *) malloc((sizeOfUnhashedFile + 1) * sizeof(BYTE));    // Allokerer nok minne for filen og \0
    fread(buffer, sizeOfUnhashedFile, 1, fr);                            // Legger inn filen i det allokerte minnet

    char *ownHash; //= malloc(16 * sizeof(BYTE)+1);
    ownHash = getChecksumOfString(buffer, sizeOfUnhashedFile);
    printf("ownHash er: \n");
    printHash(ownHash);
    free(buffer);
    buffer = NULL;

    fclose(fr);
    printf("Har lukket filen og skal sammenligne hash og lastStringFile. \n");


    // TODO Fungerer ikke fordi jeg sammenligner hashen fra hele filen og den siste delen av filen
    // TODO Burde sjekke bakerste del av filen opp mot egenkalkulert hash fra resten av filen.
    if (strcmp(ownHash, lastPartOfFile) == 0) {
        printf("Hashene var de samme i checkIfChecksumInEndOfFile-metoden. \n");
        printf("Den opprinnelige hashen: ");
        printHash(ownHash);
        printf("Den egenlagde hashen: ");
        printf("%s \n",lastPartOfFile);
        //free(lastStringFile);
        return true;
    }
    printf("Hashene var ikke det samme. \n");
    printf("Den egenproduserte hashen var: \n");
    printHash(ownHash);
    printf("Den bakerste delen av filen var: \n");
    printf("%s \n",lastPartOfFile);
    printf("Hashene var ikke det samme i checkIfChecksumInEndOfFile. \n");

    free(ownHash);
    return true;
}