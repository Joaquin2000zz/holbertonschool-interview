#ifndef SLIDE_REGION
#define SLIDE_REGION

#include <stddef.h>
#include <stdio.h>

#define SLIDE_LEFT 420
#define SLIDE_RIGHT 69
int slide_line(int *line, size_t size, int direction);
void fix(int *line, size_t size, int direction);

#endif