#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *
_system_depended_path (const char *path)
{
  #if defined(_WIN16) || defined(_WIN32)
    size_t path_length = strlen(path);
    char *win_path = malloc(path_length + 1);

    for (size_t i = 0; i <= path_length; ++i)
      if (path[i] == '/')
        win_path[i] = '\\';
      else
        win_path[i] = path[i];

    return win_path;
  #else
    return path;
  #endif
}

int
wide_system_system (const char *command)
{
  return system(_system_depended_path(command));
}

FILE *
wide_system_fopen (const char *filename, const char *mode)
{
  return fopen(_system_depended_path(filename), mode);
}

FILE *
wide_system_freopen (const char *filename, const char *mode, FILE *stream)
{
  return freopen(_system_depended_path(filename), mode, stream);
}

