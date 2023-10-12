#include "utils.h"

bool read_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file)
    return false;

  char *line = NULL;
  size_t linesize = 0;

  while (getline(&line, &linesize, file) != -1) {
    printf("%s", line);
    free(line);
  }

  free(line);
  fclose(file);

  return true;
}
