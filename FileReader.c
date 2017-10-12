//
// Created by bragalund on 12.10.17.
//


#include "FileReader.h"

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
