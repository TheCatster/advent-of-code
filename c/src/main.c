#include "main.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <year> <day> <input_file>\n", argv[0]);
    return 1;
  }

  int year = atoi(argv[1]);
  int day = atoi(argv[2]);

  printf("Running Advent of Code for year %d day %d.\n", year, day);

  FILE *file = fopen(argv[3], "r");
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

  return EXIT_SUCCESS;
}
