#ifndef COMPILATION_H_INCLUDED
#define COMPILATION_H_INCLUDED

enum Language {UNDEFINED, GCC};

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

compilation_report
compile_it(const char * inpath, const char * outpath, Language lang);

Language
lang_from_string(const char * c);

#endif // COMPILATION_H_INCLUDED
