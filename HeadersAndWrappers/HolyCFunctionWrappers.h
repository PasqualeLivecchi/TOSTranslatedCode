#ifndef HOLYC_FUNCTION_WRAPPER_H
#define HOLYC_FUNCTION_WRAPPER_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "HolyCTypeWrappers.h"

#define CAlloc(x) calloc(x,1)
#define Free(x) free(x)
#define MemCpy(x,y,z) memcpy(x,y,z)
#define StrCpy(x,y) strcpy(x,y)

void *MAlloc(U64 x)
{
return malloc(x);
}

//crude hack for now
#define CTask void
void *MAlloc(U64 x, CTask* y)
{
return malloc(x);
}

#define MemSet(x,y,z) memset(x,y,z)
#define StrLen(x) strlen(x)
#endif
