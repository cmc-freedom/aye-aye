#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

#include "compilation.h"

typedef enum
{
  OK,
  COMPILATION_ERROR,
  WRONG_ANSWER,
  TIME_LIMIT,
  MEMORY_LIMIT,
  IN_QUEUE,
  TESTING,
  CRASH,
  SYSTEM_BUG,
  PRESENTATION_ERROR
}
SolutionStatus;

typedef struct {
  int id;
  Compiled_program compiled_program;
  Solution_status status;
  char * report;
  unsigned ok_tests;
  unsigned score;
}
Solution;

#endif // SOLUTION_H_INCLUDED
