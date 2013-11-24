#ifndef COMPILATION_H_INCLUDED
#define COMPILATION_H_INCLUDED

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "compilation.h"


typedef enum {UNDEFINED, GCC} Language;

typedef struct {
  int id;
  char * path;
  Language lang;
} Compiled_program;

typedef struct {
  int status;
  char * message;
  Compiled_program result;
} Compilation_report;


Language
lang_from_string(const char * c)
{
  char * s;
  s = malloc(sizeof(c));
  int i;
  for(i = 0; c[i]; ++i)
    s[i] = tolower(c[i]);
  s[i] = '\0';
  if (!strcmp(s, "c") || !strcmp(s, "gcc"))
    return GCC;
  return UNDEFINED;
}

#endif // COMPILATION_H_INCLUDED
