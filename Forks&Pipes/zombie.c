// program creating a zombie process for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <unistd.h>
int main(void) {
  printf("Hello from main \n");

  if (fork() != 0) {
    /* THIS IS THE PARENT */
    printf("Hello from Parent\n");
    sleep(4);
  } else {
    printf("Parent PID of Child before sleep %d\n", getppid());
    sleep(2);
    printf("Parent PID of Child after sleep  %d\n", getppid());
  }
  return 0;
}
