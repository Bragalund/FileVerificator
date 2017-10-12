//
// Created by bragalund on 12.10.17.
//


#ifndef LOSNING_UTIL_H
#define LOSNING_UTIL_H

#include "md5.h"

BYTE *getChecksumOfString(char *chars, long amount);
void printHash(BYTE *hash);

#endif //LOSNING_UTIL_H
