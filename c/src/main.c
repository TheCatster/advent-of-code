#include "main.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <year> <day> <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  uint16_t year = atoi(argv[1]);
  uint8_t day = atoi(argv[2]);

  printf("Running Advent of Code for year %d day %d.\n", year, day);

  size_t line_count;
  char **input = read_input(argv[3], &line_count);

  if (!input) {
    return EXIT_FAILURE;
  }

  free(input);

  return EXIT_SUCCESS;
}
