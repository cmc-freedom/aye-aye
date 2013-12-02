#ifndef COMPILATION_H_INCLUDED
#define COMPILATION_H_INCLUDED

typedef enum
{
  UNDEFINED,
  GCC
}
Language;

typedef struct
{
  char *path;
  Language lang;
}
CompiledProgram;

typedef struct
{
  int status;
  char *message;
  CompiledProgram result;
}
CompilationReport;

CompilationReport
compile_it (const char *inpath, const char *outpath, Language language);

Language
lang_from_string (const char *string);

#endif // COMPILATION_H_INCLUDED

