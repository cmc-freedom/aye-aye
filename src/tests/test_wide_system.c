#include "wide_system.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *input_filename = "test_wide_system_in.txt";
const char *output_filename = "test_wide_system_out.txt";
const char *test_string = "abacaba";

int
main (void)
{
  size_t length_test_string = strlen(test_string);
  char scan_string[length_test_string + 2]; // space for '\n' and '\0'
  char another_scan_string[length_test_string + 2];

  char test_input_filename[3 + strlen(input_filename)];
  strcpy(test_input_filename, "./");
  strcat(test_input_filename, input_filename);

  char test_output_filename[3 + strlen(output_filename)];
  strcpy(test_output_filename, "./");
  strcat(test_output_filename, output_filename);

  FILE *test_file = fopen(input_filename, "w");
  assert(test_file != NULL);
  fputs(test_string, test_file);
  fclose(test_file);


  FILE *input = wide_system_fopen(test_input_filename, "r");
  assert(input != NULL);

  strcpy(scan_string, "");
  fgets(scan_string, length_test_string + 2, input);

  fclose(input);

  FILE *output = wide_system_fopen(test_output_filename, "w");
  assert(output != NULL);

  fputs(scan_string, output);

  fclose(output);


  test_file = fopen(output_filename, "r");
  assert(test_file != NULL);
  strcpy(another_scan_string, "");
  fgets(another_scan_string, length_test_string + 2, test_file);
  fclose(test_file);

  assert( !strcmp(scan_string, another_scan_string) );

  remove(input_filename);
  remove(output_filename);
  return 0;
}

