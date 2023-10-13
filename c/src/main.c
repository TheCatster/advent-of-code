#include "main.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <year> <day> <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  uint16_t year = atoi(argv[1]);
  uint8_t day = atoi(argv[2]);
  size_t line_count;
  char **lines = read_all_lines(argv[3], &line_count);

  printf("Running Advent of Code for year %d day %d.\n", year, day);

  if (!lines) {
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < line_count; i++) {
    printf("%s\n", lines[i]);
    free(lines[i]);
  }

  free(lines);
  return EXIT_SUCCESS;
}
