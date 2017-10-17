#include "Util.h"
#include "main.h"
#include "md5.h"
#include "ValidateInput.h"
#include "FileWriter.h"
#include "FileReader.h"


int main(int iArgc, char *iArgv[]) {


    char *command = malloc(6 * sizeof(char));
    char *lastPartOfFile= malloc(100 * sizeof(char));

    if (validationIsGood(iArgc, iArgv, command)) {
        strcpy(command, iArgv[1]);

        char *filename = malloc(sizeof(iArgv[2]));
        strcpy(filename, iArgv[2]);

        BYTE *hash;
        hash = calculateMD5Checksum(filename);

        getLast32CharsOfFile(filename, lastPartOfFile);

        if (strcmp(command, "-add") == 0) {
            if (addChecksumToFile(filename, hash)) {
                printf("Checksum was printed to file.\n");
            } else {
                printf("Something went wrong when printing hash to file.\n");
            }

        } else if (strcmp(command, "-test") == 0) {

            if(checkIfChecksumInEndOfFile(filename, lastPartOfFile)){
                printf("Checksum was correct. File has not changed. \n");
            }
            else{
                printf("File has changed or there was never a checksum in file.\n");
            }

        } else if (strcmp(command, "-strip") == 0) {

            if(checkIfChecksumInEndOfFile(filename, lastPartOfFile)){
                if(removeChecksumFromFile(filename)){
                    printf("Checksum was removed from file. \n");
                }
                else{
                    printf("Something went wrong when removing checksum.\n");
                }
            }else{
                printf("No checksum in end of file.\n Nothing to remove. \n");
            }

        }

        // Ingen else

        free(hash);
        free(filename);
    }

    free(command);

    return 0;
}




