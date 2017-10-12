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
#include <unistd.h>
#include "md5.h"
#include "md5.c"


void printHashToFile(const BYTE *hash, FILE *file);

void printHash(BYTE *hash);

//char *getHash(const BYTE *hash, char hashAsString[]);

BYTE *getChecksumOfString(char *chars, long amount);

void getLastPartOfFile(char *filename, char *lastPartOfFile);

long getSizeOfFileBySeek(FILE *fr, long sizeToBeRemoved);

long getSizeOfFile(char *filename);

bool validationIsGood(int iArgc, char *iArgv[], char *command);

bool addChecksumToFile(char *filename, BYTE *checksum);

bool removeChecksumFromFile(char *filename, char *checksum);

// bool checkIfChecksumInEndOfFile(char *filename, char *hash);

BYTE* calculateMD5Checksum(char *filename);

bool stripMD5ChecksumFromFile(FILE file);


int main(int iArgc, char *iArgv[]) {

    printf("Program started.\n");


    char *command = malloc(6 * sizeof(char));   // Definerer peker til kommando
    char *lastPartOfFile= malloc(100 * sizeof(char));
    long *sizeOfHash = malloc(32 * sizeof(long));

    printf("Allocated memory for the *command\n");

    if (validationIsGood(iArgc, iArgv, command)) {
        strcpy(command, iArgv[1]);
        printf("Command is: %s\n", command);

        char *filename = malloc(sizeof(iArgv[2]));
        strcpy(filename, iArgv[2]);

        printf("Filnavnet er: %s \n", filename);

        BYTE *hash;
        hash = calculateMD5Checksum(filename);
        printf("The hash is in the main-method is: \n");
        printHash(hash);

        getLastPartOfFile(filename, lastPartOfFile);
        //checkIfChecksumInEndOfFile(filename, hash);
        printf("Har laget MD5_CTX-objekt og er i main\n");

        if (strcmp(command, "-add") == 0) {
            printf("-add command was executed. \n");
            if (addChecksumToFile(filename, hash)) {
                printf("Checksum was printed to file.\n");
            } else {
                printf("Something went wrong when printing hash to file.\n");
            }

        } else if (strcmp(command, "-test") == 0) {
            printf("-test command was executed. \n");


        } else if (strcmp(command, "-strip") == 0) {
            printf("-strip command was executed. \n");

        }

        // Ingen else, for sikkerhets skyld.

        free(hash);
        free(filename);
        printf("Har frigjort minne for: hash, ctx og filename \n");
    }

    free(command);        // Fjerner command fra heap
    printf("Har frigjort minne for command\n");

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
        printf("File: %s exists \n", iArgv[2]);
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

bool addChecksumToFile(char *filename, BYTE *checksum) {
    printf("Gikk inn i addChecksumToFile-metoden.\n");
    long getPreviousSize = getSizeOfFile(filename); //Lagrer filstørrelsen for å kunne sjekke om den er annerledes etter å ha skrevet til filen
    FILE *fp;                                       // Deklarerer filåpner
    fp = fopen(filename, "a");                      // Bruker append på filen
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

bool removeChecksumFromFile(char *filename, char *checksum) {}

//
//bool checkIfChecksumInEndOfFile(char *filename, char *hash) {
//    printf("Entered checkIfChecksumInEndOfFile.\n");
//    FILE *fr;
//    fr = fopen(filename, "r");              // åpner fil for å bli lest
//    long sizeOfHash = sizeof(hash)*4+1;     // finner størrelsen av hashen som er
//    char *lastStringFile = getLastPartOfFile(fr, sizeOfHash);
//
//    //Kalkuler egen hash fra resten av filen -------------
//    printf("Prøver å kalkulere egen hash basert på fil... \n");
//    long sizeOfUnhashedFile = getSizeOfFile(filename) - sizeOfHash;
//
//    char *buffer;
//    buffer = (char *) malloc((sizeOfUnhashedFile + 1) * sizeof(BYTE));    // Allokerer nok minne for filen og \0
//    fread(buffer, sizeOfUnhashedFile, 1, fr);                            // Legger inn filen i det allokerte minnet
//
//    char *ownHash; //= malloc(16 * sizeof(BYTE)+1);
//    ownHash = getChecksumOfString(buffer, sizeOfUnhashedFile);
//    printf("ownHash er: \n");
//    printHash(ownHash);
//    free(buffer);
//    buffer = NULL;
//
//    fclose(fr);
//    printf("Har lukket filen og skal sammenligne hash og lastStringFile. \n");
//
//
//    // TODO Fungerer ikke fordi jeg sammenligner hashen fra hele filen og den siste delen av filen
//    // TODO Burde sjekke bakerste del av filen opp mot egenkalkulert hash fra resten av filen.
//    if (strcmp(ownHash, lastStringFile) == 0) {
//        printf("Hashene var de samme i checkIfChecksumInEndOfFile-metoden. \n");
//        printf("Den opprinnelige hashen: ");
//        printHash(ownHash);
//        printf("Den egenlagde hashen: ");
//        printHash(lastStringFile);
//        //free(lastStringFile);
//        return true;
//    }
//    printf("Hashene var ikke det samme. \n");
//    printf("Den egenproduserte hashen var: \n");
//    printHash(ownHash);
//    printf("Den bakerste delen av filen var: \n");
//    printHash(lastStringFile);
//    printf("Hashene var ikke det samme i checkIfChecksumInEndOfFile. \n");
//
//    free(ownHash);
//    //free(lastStringFile);
//    //printf("Har frigjort lastStringFile. \n");
//    return true;
//}

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

//
//char *getLastPartOfFile(FILE *fr, long sizeOfHash) {
//    char *someBuffer = (char *) malloc(sizeof(sizeOfHash) +1);
//    printf("Er inni getLastPartOfFile. \n");
//    printf("sizeofHash er %ld \n", sizeOfHash);
//    fseek(fr, -sizeOfHash, SEEK_END);                   // Søk til slutten av filen minus størrelsen på hashen
//    printf("Stopped pointer at %ld \n", ftell(fr));
//    //TODO Les hele den siste hashen. Den siste bokstaven i hashen mangler.
//    fread(someBuffer, sizeOfHash-1, 1, fr);     // Leser bytes på enden av filen
//    // (size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream))
//    /*
//             ptr − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
//             size − This is the size in bytes of each element to be read.
//             nmemb − This is the number of elements, each one with a size of size bytes.
//             stream − This is the pointer to a FILE object that specifies an input stream.
//    */
//    printf("someBuffer er %s ", someBuffer);
//    //printHash(someBuffer);
//    fseek(fr, 0, SEEK_SET);     //Setter pekeren til filen til starten av filen
//
//    return someBuffer;
//}


BYTE* calculateMD5Checksum(char *filename) {
    printf("Gikk inn i calculateMD5Checksum-metoden \n");

    long unsignedSize = getSizeOfFile(filename);           // Gjør om long til unsigned long
    printf("Konvertert om til unsignedSize(%lu) \n", unsignedSize);

    FILE *fr;
    fr = fopen(filename, "r");                                      //Åpner fil med lese-egenskaper
    printf("Har åpnet fil %s \n.", filename);

    char *buffer;
    buffer = (char *) malloc((unsignedSize + 1) * sizeof(BYTE));    // Allokerer nok minne for filen og \0
    fread(buffer, unsignedSize, 1, fr);                            // Legger inn filen i det allokerte minnet
    BYTE *hash = getChecksumOfString(buffer, unsignedSize);

    fclose(fr);
    free(buffer);

    printf("Har lukket fil og frigjort minne for buffer. \n");
    return hash;
}

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


long getSizeOfFile(char *filename) {
    FILE *fr;
    fr = fopen(filename, "r");
    printf("Har gått inn i getSizeOfFile-metoden. \n");
    long totalSizeOfFile = getSizeOfFileBySeek(fr, 0);      // 0 betyr: ikke fjern noe fra størrelsen
    fclose(fr);                                             // Lukker filen
    printf("Har lukket filen i getSizeOfFile-metoden \n");
    return totalSizeOfFile;
}

long getSizeOfFileBySeek(FILE *fr, long sizeToBeRemoved) {
    printf("Har gått in i getSizeOfFileBySeek-metoden. \n");
    fseek(fr, 0, SEEK_END);                     // Søk til slutten av filen
    printf("ftell(fr) is: %ld \n", ftell(fr));
    long size = ftell(fr) - sizeToBeRemoved;     // Få filpekerens verdi og fjern ønsket mengde
    printf("size is: %ld \n", size);
    fseek(fr, 0, SEEK_SET);                     // Søk tilbake til starten av filen
    return size;
}




//char *getHash(const BYTE *hash, char hashAsString[]) {
//    //int i;
//    printf("Har gått inn i getHash. \n");
//    //for (i = 0; i < 16; i++) {
//        if(sprintf(hashAsString, "%02x", hash) >= 32 * sizeof(BYTE)){
//            printf("Something went wrong in snprintf \n");
//            printf("hashAsString is not large enough. \n");
//        }else{
//            printf("hashAsString: %s \n", hashAsString);
//        }
//    //}
//    return hashAsString;
//}




void printHashToFile(const BYTE *hash, FILE *file) {
    int i;
    fprintf(file, "\n");
    for (i = 0; i < 16; i++) {
        fprintf(file, "%02x", hash[i]);

    }
}


void printHash(BYTE *hash) {
    int i;
    for (i = 0; i < 16; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

bool stripMD5ChecksumFromFile(FILE file) {}




