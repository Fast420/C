// program illustrating pipe after fork for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //pipe(), fork()
#include <sys/wait.h>

static void checkSysCall(int status, char *fn) {
  if (status < 0) { // error
    perror(fn);
    exit(1);
  }
}

int main(void) {
  char string1[] = "Hello Mate";
  char string2[ ]= "XXXXXXXXXX";
  char string3[] = "*Get Lost*";
  int fd_pc[2], fd_cp[2];
  int status;
  status = pipe(fd_pc);
  checkSysCall(status, "pipe");
  status = pipe(fd_cp);
  checkSysCall(status, "pipe");
  if (fork()) {
    /* PARENT */
    close(fd_pc[0]); /* close read  pc */
    close(fd_cp[1]); /* close write cp */
    write(fd_pc[1], string1, strlen(string1));
    printf("PARENT - string2 BEFORE pipe: %s\n", string2);
    read(fd_cp[0], string2, strlen(string1));
    printf("PARENT - string2  AFTER pipe: %s\n", string2);
    wait(&status);
  } else {
    /* CHILD */
    close(fd_pc[1]); /* close write pc*/
    close(fd_cp[0]); /* close read  cp*/
    printf("CHILD - string2 BEFORE pipe: %s\n", string2);
    read(fd_pc[0], string2, strlen(string1));
    printf("CHILD - string2  AFTER pipe: %s\n", string2);
    write(fd_cp[1], string3, strlen(string3));
  }
  return 0;
}
