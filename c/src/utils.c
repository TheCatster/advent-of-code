#include "utils.h"

char *read_line(FILE *file) {
  size_t buffer_size = INITIAL_BUFFER_SIZE;
  char *buffer = malloc(buffer_size);
  if (!buffer) {
    perror("Failed to allocate memory");
    return NULL;
  }

  char *current_position = buffer;
  size_t total_read = 0;

  while (fgets(current_position, buffer_size - total_read, file)) {
    size_t len = strlen(current_position);

    // If we read a newline, we've reached the end of a line
    if (current_position[len - 1] == '\n') {
      current_position[len - 1] = '\0'; // Remove newline character
      return buffer;
    }

    // If we got here, it means the buffer was too small. Expand it.
    total_read += len;
    buffer_size *= 2;
    buffer = realloc(buffer, buffer_size);
    if (!buffer) {
      perror("Failed to reallocate memory");
      return NULL;
    }

    current_position = buffer + total_read; // move to where we left off
  }

  // Handle edge case where the file doesn't end with a newline
  if (total_read > 0) {
    return buffer;
  }

  // We've reached the end of the file or an error occurred
  free(buffer);
  return NULL;
}

char **read_all_lines(const char *filename, size_t *line_count) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open file");
    return NULL;
  }

  size_t max_lines = INITIAL_LINES_SIZE;
  char **lines = malloc(max_lines * sizeof(char *));
  if (!lines) {
    perror("Failed to allocate memory for lines");
    fclose(file);
    return NULL;
  }

  *line_count = 0;
  char *line;
  while ((line = read_line(file)) != NULL) {
    if (*line_count == max_lines) { // resize if needed
      max_lines *= 2;
      char **new_lines = realloc(lines, max_lines * sizeof(char *));
      if (!new_lines) {
        perror("Failed to reallocate memory for lines");
        for (size_t i = 0; i < *line_count; i++) {
          free(lines[i]);
        }
        free(lines);
        fclose(file);
        return NULL;
      }
      lines = new_lines;
    }
    lines[(*line_count)++] = line;
  }

  fclose(file);
  return lines;
}
