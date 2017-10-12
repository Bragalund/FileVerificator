//
// Created by bragalund on 12.10.17.
//


#include "FileChanger.h"


void printHashToFile(const BYTE *hash, FILE *file) {
    int i;
    fprintf(file, "\n");
    for (i = 0; i < 16; i++) {
        fprintf(file, "%02x", hash[i]);

    }
}