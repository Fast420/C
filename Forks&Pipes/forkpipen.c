// program illustrating pipe after fork for ANU's CDS fork/pipe Lab 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //pipe(), fork()
#include <sys/wait.h>
#include <assert.h>

static void checkSysCall(int status, char *fn) {
  if (status < 0) { // error
    perror(fn);
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  int n, *buf1, *buf2, len, total, nbytes;
  int fd_pc[2], fd_cp[2];
  int status, i;
  status = pipe(fd_pc);
  checkSysCall(status, "pipe");
  status = pipe(fd_cp);
  checkSysCall(status, "pipe");

  if (argc != 2) {
    printf("Error no input argument\n");
    exit(-1);
  } else {
    // convert the character string argument to an integer
    n = atoi(argv[1]);
  }
  len = sizeof(int)*n;
  buf1 = (int*) malloc(len);
  buf2 = (int*) malloc(len);
  assert (buf1 != NULL);
  assert (buf2 != NULL);

  if (fork()) {
    /* PARENT */
    close(fd_pc[0]); /* close read  pc */
    close(fd_cp[1]); /* close write cp */

    for (i=0; i < n; i++) 
      buf1[i] = n;
        printf("%s\n","before");
    nbytes = write(fd_pc[1], buf1, len);
                    printf("%s\n","test");

    nbytes = read(fd_cp[0], buf2, len);
                printf("%s\n","not get");

    total = 0;
    for (i=0; i < n; i++)
      total += buf1[i]+buf2[i];
    printf("PARENT - nbytes=%d, total=%d\n", nbytes, total);
    wait(&status);
  } else {
    /* CHILD */
    close(fd_pc[1]); /* close write pc*/
    close(fd_cp[0]); /* close read  cp*/
    for (i=0; i < n; i++)
      buf2[i] = n-i;
    nbytes = read(fd_pc[0], buf1, len);
        printf("%s\n","after");
    nbytes = write(fd_cp[1], buf2, len);
        printf("%s\n","get");

    total = 0;
    for (i=0; i < n; i++)
      total += buf1[i]+buf2[i];
    printf("CHILD  - nbytes=%d, total=%d\n", nbytes, total);
  }
  return 0;
}

