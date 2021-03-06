// server program for ANU's CDS sockets Lab
// fork

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_ntoa, ntohs
#include <sys/wait.h>

void resourceError(int status, char *caller, char *msg) {
  printf("%s(): resource error status=%d\n", caller, status);
  perror(msg);
  exit(2);
}

#define MAXBUF 128

int main(int argc, char* argv[]) {
  int sock_1, sock_2;                /* two socket descriptors */
  int status;                        /* return value of system call */
  struct sockaddr_in client, server; /* address info;
					see /usr/include/linux/in.h */
  char buf[MAXBUF];                  /* data buffer */
  int nbytes;
  socklen_t namelen;

  int n, id; /* id is client's id (0 <= id < n) */
  if (argc < 2) {
    printf("Error no input argument\n");
    exit(-1);
    } else { // convert the character string argument to an integer
      n = atoi(argv[1]);
  }

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
  status = listen(sock_1, n);
  if (status != 0)
    resourceError(status, "server", "listen");

  // client
  for (id = 0; id < n; id++)
  {
    // create child
    if (fork() == 0)
    {
      // child process: id'th client
      char port_buf[16], id_buf[16];
      sprintf(port_buf, "%d", ntohs(server.sin_port));
      sprintf(id_buf, "%d", id);
      status = execl("./client2", "client2", port_buf, id_buf, (char *) NULL);
      if (status != 0)
        resourceError(status, "child", "execl");
    }
  }

  for (id = 0; id < n; id++)
  {
    /* ----Now we block waiting for a connection---- */
    namelen = sizeof(client);
    sock_2 = accept(sock_1, (struct sockaddr *) &client, &namelen);
    if (sock_2 < 0) 
      resourceError(sock_2, "server", "accept");
    getsockname(sock_2, (struct sockaddr *) &server, &namelen);
    printf("Server received connection from %s, now on port %d\n",
     inet_ntoa(client.sin_addr), ntohs(server.sin_port));

    /* ----Wait to receive some data---- */
    nbytes = recv(sock_2, buf, sizeof(buf)-1, 0);
    if (nbytes < 0) 
      resourceError(nbytes, "server", "recv");
    buf[nbytes] = 0; // do not trust client to send a null-terminated string!
    printf("Server received message: %s\n", buf);

    /* ----Add string and return to client---- */
    strncat(buf, " and hello to you client\n", MAXBUF-strlen(buf));
    nbytes = send(sock_2, buf, strlen(buf), 0);
    if (nbytes < 0) 
      resourceError(nbytes, "server", "send");

    // the server terminates after the client
    wait(&status);

    /* ----Close sockets and terminate---- */
    close(sock_2);
    close(sock_1);
    printf("Server finished.\n");
   }
  return 0;
}

