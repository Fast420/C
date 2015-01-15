// program illustrating pipes in a single process for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <stdlib.h> //exit()
#include <string.h>
#include <unistd.h> //pipe()
int main(void) {
  int status, nbytes;
  char string1[] = "Yunen";
  char string2[] = "He";
  int my_pipe[2];
  int len1, len2;
  status = pipe(my_pipe);
  if (status < 0) {
    perror("pipe"); exit(1);
  }

  len1 = strlen(string1);
  len2 = strlen(string2);
  printf("initial string1: \"%s\", length %d\n", string1, len1);
  printf("initial string2: \"%s\", length %d\n", string2, len2);

  nbytes = write(my_pipe[1], string1, len1);
  printf("write(): %d bytes\n", nbytes);
  nbytes = read(my_pipe[0], string2, len2);
  printf("read(): %d bytes\n", nbytes);
  printf("read(): dest. string: \"%s\"\n", string2);
  return 0;
}
