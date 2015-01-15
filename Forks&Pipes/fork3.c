// modified fork program writing to file for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <unistd.h>
int main(void) {
  pid_t fork_pid;
  FILE *my_file;

  my_file=fopen("MY_FORK_FILE.txt", "w");
  fprintf(my_file, "Hello from main\n");

  // Calling the fflush() function causes any bufferd data in the output buffer to be sent to the
  // output file identified by fp .
  fflush(my_file);

  fork_pid = fork();
  fprintf(my_file, "After fork fork_pid=%d\n", fork_pid);

  return 0;
}


/**
http://man7.org/linux/man-pages/man3/fflush.3.html

For output streams, fflush() forces a write of all user-space
buffered data for the given output or update stream via the stream's
underlying write function.

print Hello from main\n one time

**/