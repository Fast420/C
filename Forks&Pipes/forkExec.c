#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (fork()==0) { // I am the child
    execlp("/bin/ls", "ls", "-l", "-t", (char *) NULL);
    abort();
  } else {
    // rest of parent program
    int childStatus;
    printf("parent has forked a grep child. Waiting...\n");
    wait(&childStatus);
    return (0);
  }
}