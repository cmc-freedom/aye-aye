#ifndef PROBLEM_H_INCLUDED
#define PROBLEM_H_INCLUDED

#include <stdbool.h>

typedef enum
{
  OK,
  CHECHER_ERROR,
  GENERATOR_ERROR,
  DATA_ERROR,
  CONFIG_ERROR,
  EXISTING_NAME
}
ProblemStatus;

typedef struct
{
  unsigned time;
  unsigned memory;
}
Limits;

typedef struct
{
  int id;
  char *name;
  char *checker;
  char *generator;
  char *data;
  char *config;
  bool cached;
  Limits limit;
  unsigned tests_count;
}
Problem;

ProblemStatus
create_problem (char *config, Problem *problem);

void
delete_problem (char *name);

ProblemStatus
reload_problem (char *name);

ProblemStatus
replace_problem (char *config_path, Problem *problem);

Problem
load_problem (char *name);

void
export_problem (char *path);

ProblemStatus
import_problem (char *path);

#include "problem.c"

#endif // PROBLEM_H_INCLUDED
