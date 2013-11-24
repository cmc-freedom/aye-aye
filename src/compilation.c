#ifndef COMPILATION_H_INCLUDED
#define COMPILATION_H_INCLUDED

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "compilation.h"

typedef enum {UNDEFINED, GCC} Language;

typedef struct{
  char * path;
  Language lang;
} Compiled_program;

typedef struct{
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

Compilation_report
compile_it(const char * inpath, const char * outpath, Language lang)
{
  Compilation_report report;
  report.result.path = malloc(sizeof(outpath));
  strcpy(report.result.path, outpath);
  report.result.lang = lang;
  switch(lang)
  {
    case GCC: exec_GCC(inpath, &report); break;
    default: exec_UNDEFINED(&report);
  }
  return report;
}

void exec_GCC(const char * path, Compilation_report * report)
{
  //exec for gcc
}

void exec_UNDEFINED(Compilation_report * report)
{
  char c[] = "Undefined language";
  free(report->result.path);
  report->status = -1;
  report->message = malloc(sizeof(c));
  strcpy(report->message, c);
}

#endif // COMPILATION_H_INCLUDED
