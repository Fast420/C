// program demonstrating Posix select for ANU's CDS sockets Lab 

#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/time.h> 
#include <sys/wait.h>

void resourceError(int status, char *caller, char *msg) {
  printf("%s(): resource error status=%d\n", caller, status);
  perror(msg);
  exit(2);
}

#define MAXBUF 32
#define NUM_CHILD 2
#define COUNT_MAX 20

int main(int argc, char* argv[]) {
  int fd_pc[NUM_CHILD][2], fd_cp[NUM_CHILD][2];
  int maxfd;
  fd_set fd_read_set;
  char buffer[MAXBUF];
  int i, counter, status;
      
  /* ----Create the pipes---- */
  for (i=0; i < NUM_CHILD; i++) {
    status = pipe(fd_pc[i]) | pipe(fd_cp[i]);
    if (status < 0)
      resourceError(status, "selectpipe", "pipe");
  }
      
  for (i=0; i < NUM_CHILD; i++) {
    /* ----Create child i ---- */
    int pid = fork();
    if (pid < 0)
      resourceError(status, "selectpipe", "fork");
    if (pid == 0) { /* ---- perform child i  ---- */
      int count;
      close(fd_pc[i][1]); /*Close parent to child write*/
      close(fd_cp[i][0]); /*Close child to parent read*/
      sprintf(buffer, "Request from child %d", i);
      do {
        write(fd_cp[i][1], buffer, MAXBUF);
        read(fd_pc[i][0], &count, sizeof(count));
        printf("Value of counter on child %d: %d\n", i, count);
        fflush(stdout);
        sleep(i+1);
      } while (count > 0);
      printf("Child %d terminates\n", i);
      fflush(stdout);
      close(fd_pc[i][0]); close(fd_cp[i][1]);
      exit(0);
    }
  }
 
  /* ----Now for the parent---- */
  for (i=0; i < NUM_CHILD; i++) {
    close(fd_pc[i][0]); /*Close parent to child read*/  
    close(fd_cp[i][1]); /*Close child to parent write*/
  }
      
  /* ----What is the maximum file descriptor for select---- */
  maxfd = fd_cp[0][0];
  for (i=1; i < NUM_CHILD; i++)
    if (fd_cp[i][0] > maxfd)
      maxfd = fd_cp[i][0];
  maxfd = maxfd + 1;
      
  counter = 0;
  /* ----Clear the read set---- */
  FD_ZERO(&fd_read_set);
  while (counter < COUNT_MAX) {
    /* ----Set file descriptor set to NUM_CHILD read descriptors---- */
    for (i=0; i < NUM_CHILD; i++) {
      FD_SET(fd_cp[i][0], &fd_read_set);
    }

    /* ----Wait in select until file descriptors change---- */
    select(maxfd, &fd_read_set, NULL, NULL, NULL);

    for (i=0; i < NUM_CHILD; i++) {
      /* ----Was it child i---- */
      if (FD_ISSET(fd_cp[i][0], &fd_read_set)) {
        read(fd_cp[i][0], buffer, MAXBUF);
        printf("%s\n", buffer);
        counter++;
        write(fd_pc[i][1], &counter, sizeof(counter));
      }
    }
  }
    
  /* ---- Request the children to terminate and wait ---- */
  counter = -1;
  for (i=0; i < NUM_CHILD; i++) {
    write(fd_pc[i][1], &counter, sizeof(counter));
    close(fd_pc[i][1]); close(fd_cp[i][0]);  
  }
  for (i=0; i < NUM_CHILD; i++)
    wait(NULL);
  exit(0);
}

