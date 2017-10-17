
#include "FileReader.h"
#include "Util.h"

long getSizeOfFile(char *filename) {
    FILE *fr;
    fr = fopen(filename, "r");
    long totalSizeOfFile = getSizeOfFileBySeek(fr, 0);      // 0 betyr: ikke fjern noe fra størrelsen
    fclose(fr);                                             // Lukker filen
    return totalSizeOfFile;
}

long getSizeOfFileBySeek(FILE *fr, long sizeToBeRemoved) {
    fseek(fr, 0, SEEK_END);                     // Søk til slutten av filen
    long size = ftell(fr) - sizeToBeRemoved;     // Få filpekerens verdi og fjern ønsket mengde
    fseek(fr, 0, SEEK_SET);                     // Søk tilbake til starten av filen
    return size;
}



BYTE* calculateMD5Checksum(char *filename) {

    long unsignedSize = getSizeOfFile(filename);           // Gjør om long til unsigned long

    FILE *fr;
    fr = fopen(filename, "r");                                      //Åpner fil med lese-egenskaper

    char *buffer;
    buffer = (char *) malloc((unsignedSize + 1) * sizeof(BYTE));    // Allokerer nok minne for filen og \0
    fread(buffer, unsignedSize, 1, fr);                            // Legger inn filen i det allokerte minnet
    BYTE *hash = getChecksumOfString(buffer, unsignedSize);

    fclose(fr);
    free(buffer);

    return hash;
}

void getLast32CharsOfFile(char *filename, char *lastPartOfFile){
    FILE *fr;
    fr = fopen(filename, "r");
    static const long max_len = 32+1;

    char buf[max_len + 1];              // Lager buffer for å kunne lese inn deler av filen i

    fseek(fr, -max_len+1, SEEK_END);          // Søker til slutten av filen, bortsett fra slutten
    ssize_t len = fread( buf, 1, max_len, fr);
    fclose(fr);

    buf[len] = '\0';                            // Setter EOF
    strcpy(lastPartOfFile, buf);           // Kopierer last line over til lastPartOfFile
}