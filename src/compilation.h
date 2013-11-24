#ifndef COMPILATION_H_INCLUDED
#define COMPILATION_H_INCLUDED

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


Compilation_report
compile_it(const char * inpath, const char * outpath, Language lang);

Language
lang_from_string(const char * c);

#endif // COMPILATION_H_INCLUDED
