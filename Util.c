//
// Created by bragalund on 12.10.17.
//

#include <printf.h>
#include "Util.h"
#include "md5.h"
#include "main.h"


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