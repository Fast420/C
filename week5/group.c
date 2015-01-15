#include <stdio.h>
#include <stdlib.h>

int read_line(FILE *in, char *buffer, size_t max)
{
  return fgets(buffer, max, in) == buffer;
}

int main(void)
{
  FILE *in;
  if((in = fopen("input.txt", "rt")) != NULL)
  {
    char line[256];

    if(read_line(in, line, sizeof line))
      printf("read '%s' OK", line);
    else
      printf("read error\n");
    fclose(in);
  }
  return EXIT_SUCCESS;
}