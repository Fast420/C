// fork program writing to file for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <unistd.h> //fork()
int main(void) {
  pid_t fork_pid;
  FILE *my_file;

  my_file=fopen("MY_FORK_FILE.txt", "w");
  fprintf(my_file, "Hello from main\n");
  fork_pid = fork();
  fprintf(my_file, "After fork fork_pid=%d\n", fork_pid);

  return 0;
}

/**
it also copy the io buffer
http://stackoverflow.com/questions/3513242/working-of-fork-in-linux-gcc

http://man7.org/linux/man-pages/man2/fork.2.html
The child inherits copies of the parent's set of open file
descriptors.
Each file descriptor in the child refers to the same
open file description (see open(2)) as the corresponding file
descriptor in the parent.

When fork() is called, both parent and child processes inherit the same open file descriptor,
and therefore they both wil write 'Hello from main\n' into file.

**/
