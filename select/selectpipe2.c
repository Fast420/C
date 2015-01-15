// Rewrite selectpipe.c using sockets.
// Yunen He 2014

#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/time.h> 
#include <sys/wait.h>
// added
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
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

  // added
  int sock_1, sock_2[NUM_CHILD];
  struct sockaddr_in client[NUM_CHILD], server;
  socklen_t namelen;

  /* ----Create TCP/IP socket---- */
  sock_1 = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_1 == -1) 
    resourceError(sock_1, "server", "socket");
  printf("Socket created successfully.\n");

  /* ----Address information for use with bind---- */
  server.sin_family = AF_INET;         /* it is an IP address */
  server.sin_port   = 0;               /* use O/S defined port number */
  server.sin_addr.s_addr = INADDR_ANY; /* use any interface on this host*/

  /* ----Bind socket to address and port---- */
  status = bind(sock_1, (struct sockaddr *) &server, sizeof(server)); 
  if (status != 0)
    resourceError(status, "server", "bind");

  /* ----Find out what port number was assigned---- */
  namelen = sizeof(server);
  status = getsockname(sock_1, (struct sockaddr *) &server, &namelen);
  if (status != 0)
    resourceError(status, "server", "getsockname - port number");
  printf("The assigned server port number is %d\n", ntohs(server.sin_port));

  /* ----Set queue limits on socket---- */
  status = listen(sock_1, NUM_CHILD);
  if (status != 0)
    resourceError(status, "server", "listen");

  /* ----Create the children ---- */
  for (i=0; i < NUM_CHILD; i++) {
  /* ----Create child i ---- */
    int pid = fork();
    if (pid < 0)
      resourceError(status, "selectsock", "fork");

    if (pid == 0) 
    { /* ---- perform child i ---- */
      close(sock_1); // close the parent's listening socket
      sock_1 = socket(AF_INET, SOCK_STREAM, 0);

      if (sock_1 < 0)
        resourceError(sock_1, "selectsock child", "socket");
      printf("Client %d socket created\n", i);

      /* ----Attempt to connect to the server; n.b. server struct set by parent */
      status = connect(sock_1, (struct sockaddr *) &server, sizeof(server));
      if (status != 0)
        resourceError(status, "selectsock child", "connect");
    }
  }

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
      close(sock_2[i]); /*Close parent to child write*/
      close(sock_2[i]); /*Close child to parent read*/
      sprintf(buffer, "Request from child %d", i);
      do {
        write(sock_1, buffer, MAXBUF);
        read(sock_1, &count, sizeof(count));
        printf("Value of counter on child %d: %d\n", i, count);
        fflush(stdout);
        sleep(i+1);
      } while (count > 0);
      printf("Child %d terminates\n", i);
      fflush(stdout);
      close(sock_1); close(sock_1);
      exit(0);
    }
  }
 
  /* ----Now for the parent---- */
  for (i=0; i < NUM_CHILD; i++) {
    namelen = sizeof(client[i]);
    sock_2[i] = accept(sock_1, (struct sockaddr *) &client[i], &namelen);
    if (sock_2[i] < 0)
      resourceError(status, "parent", "accept");

    printf("Server received connection from child %d %s\n",i, inet_ntoa(client[i].sin_addr));
  }

  /* ----What is the maximum file descriptor for select---- */
  maxfd = fd_cp[0][0];
  for (i=1; i < NUM_CHILD; i++)
    if (sock_2[i] > maxfd)
      maxfd = sock_2[i];
  maxfd = maxfd + 1;
      
  counter = 0;
  /* ----Clear the read set---- */
  FD_ZERO(&fd_read_set);
  while (counter < COUNT_MAX) {
    /* ----Set file descriptor set to NUM_CHILD read descriptors---- */
    for (i=0; i < NUM_CHILD; i++) {
      FD_SET(sock_2[i], &fd_read_set);
    }

    /* ----Wait in select until file descriptors change---- */
    select(maxfd, &fd_read_set, NULL, NULL, NULL);

    for (i=0; i < NUM_CHILD; i++) {
      /* ----Was it child i---- */
      if (FD_ISSET(sock_2[i], &fd_read_set)) {
        read(sock_2[i], buffer, MAXBUF);
        printf("%s\n", buffer);
        counter++;
        write(sock_2[i], &counter, sizeof(counter));
      }
    }
  }
    
  /* ---- Request the children to terminate and wait ---- */
  counter = -1;
  for (i=0; i < NUM_CHILD; i++) {
    write(sock_2[i], &counter, sizeof(counter));
    close(sock_2[i]); close(sock_2[i]);  
  }
  for (i=0; i < NUM_CHILD; i++)
    wait(NULL);
  exit(0);
}

