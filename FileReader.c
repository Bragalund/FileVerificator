//
// Created by bragalund on 12.10.17.
//


#include "FileReader.h"
#include "Util.h"

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

void getLast32CharsOfFile(char *filename, char *lastPartOfFile){
    FILE *fr;
    fr = fopen(filename, "r");
    static const long max_len = 32+1;         //

    char buf[max_len + 1];              // Lager buffer for å kunne lese inn deler av filen i

    fseek(fr, -max_len+1, SEEK_END);          // Søker til slutten av filen, bortsett fra slutten
    ssize_t len = fread( buf, 1, max_len, fr);
    fclose(fr);

    buf[len] = '\0';                            // Setter EOF
    strcpy(lastPartOfFile, buf);           // Kopierer last line over til lastPartOfFile
    printf("last_line: %s \n", lastPartOfFile);
}