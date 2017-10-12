//
// Created by bragalund on 12.10.17.
//

#ifndef LOSNING_FILEREADER_H
#define LOSNING_FILEREADER_H

//Dependencies
#include "md5.h"
#include "main.h"

//Functions
long getSizeOfFile(char *filename);
long getSizeOfFileBySeek(FILE *fr, long sizeToBeRemoved);
BYTE* calculateMD5Checksum(char *filename);

#endif //LOSNING_FILEREADER_H
