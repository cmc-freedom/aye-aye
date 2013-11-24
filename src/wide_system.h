#ifndef SYSTEM_WIDE_H
#define SYSTEM_WIDE_H

#include <stdio.h>

int
wide_system_system (const char * command);

int
wide_system_fopen (const char * filename, const char * mode);

FILE *
wide_system_freopen (const char * filename, const char * mode, FILE * stream );


#endif // SYSTEM_WIDE_H
