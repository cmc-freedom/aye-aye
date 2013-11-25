#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "wide_system.h"

void
exec_GCC(const char * path, CompilationReport * report);

void
exec_UNDEFINED(CompilationReport * report);

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
  {
    free(s);
    return GCC;
  }
  free(s);
  return UNDEFINED;
}

CompilationReport
compile_it(const char * inpath, const char * outpath, Language lang)
{
  CompilationReport report;
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

void
exec_GCC(const char * path, CompilationReport * report)
{
  char name[] = "gcc ", options[] = " -std=gnu99 -o ";
  char errormsg[] = "Compile error", okmsg[] = "Successful compile";
  char * str = malloc(sizeof(name) + strlen(path) + sizeof(options) + strlen(report->result.path));
  strcpy(str, name);
  strcat(str, path);
  strcat(str, options);
  strcat(str, report->result.path);
  report->status = wide_system_system(str);
  if (report->status)
  {
    report->message = malloc(sizeof(errormsg));
    strcpy(report->message, errormsg);
  }
  else
  {
    report->message = malloc(sizeof(okmsg));
    strcpy(report->message, okmsg);
  }
  free(str);
}

void
exec_UNDEFINED(CompilationReport * report)
{
  char c[] = "Undefined language";
  free(report->result.path);
  report->status = -1;
  report->message = malloc(sizeof(c));
  strcpy(report->message, c);
}

