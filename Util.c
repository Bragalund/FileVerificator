#include "Util.h"
#include "md5.h"
#include "main.h"
#include "FileReader.h"


BYTE *getChecksumOfString(char *chars, long amount) {
    MD5_CTX *ctx = malloc(sizeof(MD5_CTX));
    md5_init(ctx);
    if (!ctx) {   // Avslutter om ctx-objekt er NULL
        printf("ctx var NULL \n");
        exit(1);
    }

    md5_update(ctx, (const BYTE *) chars, amount);               // Lager Hash av fil
    BYTE *hashBytes = malloc(16 * sizeof(BYTE));
    md5_final(ctx, hashBytes);
    free(ctx);
    return hashBytes;
}


void printHash(BYTE *hash) {
    int i;
    for (i = 0; i < 16; i++)
        printf("%02x", hash[i]);
    printf("\n");
}


bool checkIfChecksumInEndOfFile(char *filename, char *lastPartOfFile) {

    FILE *fr;
    fr = fopen(filename, "r");                                           // åpner fil for å bli lest
    long sizeOfHash = sizeof(lastPartOfFile)*4+1;                        // finner størrelsen av hashen som er


    long sizeOfUnhashedFile = getSizeOfFile(filename) - sizeOfHash;      //Kalkuler egen hash fra resten av filen


    char *buffer;
    buffer = (char *) malloc((sizeOfUnhashedFile + 1) * sizeof(BYTE));   // Allokerer nok minne for filen og \0
    fread(buffer, sizeOfUnhashedFile, 1, fr);                            // Legger inn filen i det allokerte minnet

    BYTE *ownHash;
    ownHash = getChecksumOfString(buffer, sizeOfUnhashedFile);
    free(buffer);

    fclose(fr);


    //Lagrer string representasjon av hash i variabel
    char ownHashAsString[33];
    for(int i =0; i<16; i++) {
        sprintf(ownHashAsString+(i*2), "%02x", ownHash[i]);
    }
    ownHashAsString[33] = "\0";


    if (strcmp(ownHashAsString, lastPartOfFile) == 0) {
        return true;
    }
    return false;
}