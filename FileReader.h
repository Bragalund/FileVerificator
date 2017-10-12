//
// Created by bragalund on 12.10.17.
//

#ifndef LOSNING_FILEREADER_H
#define LOSNING_FILEREADER_H

//Dependencies
#include <stdio.h>

//Functions
long getSizeOfFile(char *filename);
long getSizeOfFileBySeek(FILE *fr, long sizeToBeRemoved);

#endif //LOSNING_FILEREADER_H
