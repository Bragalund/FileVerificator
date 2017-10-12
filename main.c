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

#include "Util.h"
#include "main.h"
#include "md5.h"
#include "ValidateInput.h"
#include "FileWriter.h"
#include "FileReader.h"


void printHash(BYTE *hash);

//char *getHash(const BYTE *hash, char hashAsString[]);

BYTE *getChecksumOfString(char *chars, long amount);

void getLastPartOfFile(char *filename, char *lastPartOfFile);

bool removeChecksumFromFile(char *filename, char *checksum);

bool checkIfChecksumInEndOfFile(char *filename, char *hash);

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









bool stripMD5ChecksumFromFile(FILE file) {}




