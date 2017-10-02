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

bool validationIsGood(int iArgc, char *iArgv[], char *command);

bool addChecksumToFile(char *filename, char *checksum);

bool removeChecksumFromFile(char *filename, char *checksum);

bool checkIfChecksumInEndOfFile();

bool calculateMD5Checksum(FILE file);

bool stripMD5ChecksumFromFile(FILE file);


int main(int iArgc, char *iArgv[]) {

    printf("Program started.\n");

    //Definerer peker til kommando
    char *command = malloc(6 * sizeof(char));

    printf("Allocated memory for the *command\n");

    if (validationIsGood(iArgc, iArgv, *command)) {
        strcpy(command, iArgv[1]);
        printf("Command is: %s\n", command);

        if (strcmp(command, "-add") == 0) {
            printf("-add command was executed. \n");


        } else if (strcmp(command, "-test") == 0) {
            printf("-test command was executed. \n");


        } else if (strcmp(command, "-strip") == 0) {
            printf("-strip command was executed. \n");


        }
        // Ingen else, for sikkerhets skyld.
    }


    free(command);

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
    FILE *fp = NULL;                    //Deklarerer filåpner
    fp = fopen(filename, "a");          //bruker append
    fprintf(fp, "%s", checksum);        // writes md5 checksum to file
    fclose(fp);                         //Lukker fil
}

bool removeChecksumFromFile(char *filename, char *checksum) {}

bool checkIfChecksumInEndOfFile() {

}

bool calculateMD5Checksum(FILE file) {

}

bool stripMD5ChecksumFromFile(FILE file) {

}




