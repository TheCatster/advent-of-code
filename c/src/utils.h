#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 1024
#define INITIAL_LINES_SIZE 512

char *read_line(FILE *file);
char **read_all_lines(const char *filename, size_t *line_count);
