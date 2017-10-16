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


//char *getHash(const BYTE *hash, char hashAsString[]);


bool removeChecksumFromFile(char *filename, char *checksum);

bool checkIfChecksumInEndOfFile(char *filename, char *hash);

bool stripMD5ChecksumFromFile(FILE file);


int main(int iArgc, char *iArgv[]) {

    printf("Program started.\n");


    char *command = malloc(6 * sizeof(char));   // Definerer peker til kommando
    char *lastPartOfFile= malloc(100 * sizeof(char));

    if (validationIsGood(iArgc, iArgv, command)) {
        strcpy(command, iArgv[1]);

        char *filename = malloc(sizeof(iArgv[2]));
        strcpy(filename, iArgv[2]);

        BYTE *hash;
        hash = calculateMD5Checksum(filename);

        getLast32CharsOfFile(filename, lastPartOfFile);

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
            if(checkIfChecksumInEndOfFile(filename, lastPartOfFile)){
                printf("There was a checksum in the end of the file. \n");
            }
            else{
                printf("NO checksum in the end of the file. \n");
            }


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




