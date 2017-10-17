//
// Created by Henrik Bakkelund on 12.10.17.
//

#ifndef LOSNING_FILECHANGER_H
#define LOSNING_FILECHANGER_H

//Other dependencies
#include "md5.h"
#include "main.h"
#include <unistd.h>


//Declare functions
void printHashToFile(const BYTE *hash, FILE *file);
bool addChecksumToFile(char *filename, BYTE *checksum);
bool removeChecksumFromFile(char *filename);


#endif //LOSNING_FILECHANGER_H
