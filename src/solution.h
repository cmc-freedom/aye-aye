#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

#include "compilation.h"

enum Solution_status {
  OK,
  COMPILATION_ERROR,
  WRONG_ANSWER,
  TIME_LIMIT,
  MEMORY_LIMIT,
  IN_QUEUE,
  TESTING
};

typedef struct {
  Compiled_program compiled_program;
  Solution_status status;
} Solution;

#endif // SOLUTION_H_INCLUDED
