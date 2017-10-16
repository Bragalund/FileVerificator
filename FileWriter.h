//
// Created by Henrik Bakkelund on 12.10.17.
//

#ifndef LOSNING_FILECHANGER_H
#define LOSNING_FILECHANGER_H

//Other dependencies
#include "md5.h"
#include "main.h"


//Declare functions
void printHashToFile(const BYTE *hash, FILE *file);
bool addChecksumToFile(char *filename, BYTE *checksum);


#endif //LOSNING_FILECHANGER_H
