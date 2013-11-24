#ifndef PROBLEM_H_INCLUDED
#define PROBLEM_H_INCLUDED

#include <stdbool.h>

typedef enum {
  OK,
  CHECHER_ERROR,
  GENERATOR_ERROR,
  DATA_ERROR,
  CONFIG_ERROR,
  EXISTING_NAME
} Problem_status;

typedef struct {
  unsigned time;
  unsigned memory;
} Limits;

typedef struct {
  int id;
  char * name;
  char * checker
  char * generator;
  char * data;
  char * config_path;
  bool cached;
  Limits limit;
  unsigned tests_count;
} Problem;

Problem_status
create_problem(char * config_path, Problem * pr);

void
delete_problem(char * name);

Problem_status
reload_problem(char * name);

Problem_status
replace_problem(char * config_path, Problem * pr);

Problem
load_problem(char * name);

void
export_problem(char * path);

Problem_status
import_problem(char * path);

#endif // PROBLEM_H_INCLUDED
