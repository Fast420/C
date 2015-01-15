// simple fork program for ANU's CDS fork/pipe Lab 

#include <stdio.h>
#include <unistd.h> //fork()
int main(void) {
  pid_t fork_pid;
  printf("Hello from main\n");

  fork_pid = fork();

  if (fork_pid == 0)
    printf("child: After fork, fork_pid = %d, pid = %d, ppid = %d\n", fork_pid, getpid(), getppid());
  else
    printf("parent: After work, fork_pid = %d , pid = %d \n", fork_pid, getpid());
  return 0;
}
