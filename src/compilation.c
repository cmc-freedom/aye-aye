#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "wide_system.h"

void
exec_GCC(const char *path, CompilationReport *report);

void
exec_UNDEFINED(CompilationReport *report);

Language
lang_from_string(const char *path)
{
  char *copy = malloc(strlen(path) + 1);
  assert(copy != NULL);

  size_t i;
  for(i = 0; copy[i] != 0; ++i)
    copy[i] = tolower(path[i]);
  copy[i] = '\0';

  if (!strcmp(copy, "c") || !strcmp(copy, "gcc"))
  {
    free(copy);
    return GCC;
  }
  free(copy);
  return UNDEFINED;
}

CompilationReport
compile_it(const char *inpath, const char *outpath, Language lang)
{
  CompilationReport report;

  report.result.path = malloc(strlen(outpath) + 1);
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
exec_GCC(const char *path, CompilationReport *report)
{
  char name[] = "gcc ", options[] = " -std=gnu99 -o ";
  char errormsg[] = "Compile error", okmsg[] = "Successful compile";
  char no_result[] = "None";
  char *str = malloc(strlen(name) +
                     strlen(path) +
                     strlen(options) +
                     strlen(report->result.path) + 1);
  strcpy(str, name);
  strcat(str, path);
  strcat(str, options);
  strcat(str, report->result.path);
  report->status = wide_system_system(str);
  if (report->status)
  {
    report->result.path = malloc(strlen(no_result) + 1);
    strcpy(report->result.path, no_result);
    report->message = malloc(strlen(errormsg) + 1);
    strcpy(report->message, errormsg);
  }
  else
  {
    report->message = malloc(strlen(okmsg) + 1);
    strcpy(report->message, okmsg);
  }
  free(str);
}

void
exec_UNDEFINED(CompilationReport *report)
{
  char c[] = "Undefined language";
  free(report->result.path);
  report->status = -1;
  report->message = malloc(strlen(c) + 1);
  strcpy(report->message, c);
}

