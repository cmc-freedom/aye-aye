#ifndef SYSTEM_WIDE_H
#define SYSTEM_WIDE_H

#include <stdio.h>

int
system_wide_system (const char * command);

int
system_wide_fopen (const char * filename, const char * mode);

FILE *
system_wide_freopen (const char * filename, const char * mode, FILE * stream );


#endif // SYSTEM_WIDE_H
