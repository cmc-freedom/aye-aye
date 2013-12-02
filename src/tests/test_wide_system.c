#include "wide_system.h"

#include <assert.h>

int
main (void)
{
  FILE *input = wide_system_fopen("./test_wide_system_in.txt", "r");
  assert(input != NULL);

  char s[256];
  fgets(s, 256, input);

  fclose(input);

  FILE *output = wide_system_fopen("./test_wide_system_out.txt", "w");
  assert(output != NULL);

  fputs(s, output);
  fputc('\n', output);

  fclose(output);

  return 0;
}

