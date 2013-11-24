#ifndef PROBLEM_H_INCLUDED
#define PROBLEM_H_INCLUDED

#include <stdbool.h>

typedef struct {
  unsigned time;
  unsigned memory;
} Limits;

typedef struct {
  char * name;
  char * checker
  char * generator;
  char * data;
  bool cached;
  Limits limit;
} Problem;

#endif // PROBLEM_H_INCLUDED
