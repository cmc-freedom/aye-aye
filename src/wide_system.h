#ifndef WIDE_SYSTEM_H
#define WIDE_SYSTEM_H

#include <stdio.h>

int
wide_system_system (const char *command);

FILE *
wide_system_fopen (const char *filename, const char *mode);

FILE *
wide_system_freopen (const char *filename, const char *mode, FILE *stream);

#endif // WIDE_SYSTEM_H

