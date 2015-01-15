// client program for ANU's CDS sockets Lab 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> //htons
#include <unistd.h> //close()

void resourceError(int status, char *caller, char *msg) {
  printf("%s(): resource error status=%d\n", caller, status);
  perror(msg);
  exit(2);
}

#define MAXBUF 128

int main(int argc, char* argv[]) {
  int sock_1;                /* client socket */
  int status;                /* return value of system call */
  struct sockaddr_in server; /* server address */
  uint16_t server_port;      /* server port number */
  char buf[MAXBUF];          /* data buffer */
  int nbytes;

  int id;
  if (argc < 3) {
    printf("Usage: %s port_number_of_server client_id\n", argv[0] );
    exit(-1);
  }

  /* ----Port number on server---- */
  server_port = (unsigned short) atoi(argv[1]);
  id = atoi(argv[2]);

  /* ----Create TCP/IP socket---- */
  sock_1 = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_1 < 0) 
    resourceError(sock_1, "client", "socket");
  printf("Client socket created\n");

  /* ----Address and port information for server---- */
  server.sin_family      = AF_INET;
  server.sin_port        = htons(server_port);
  server.sin_addr.s_addr = INADDR_ANY; /* use any interface on this host*/

  /* ----Attempt to connect to the server---- */
  status = connect(sock_1, (struct sockaddr *) &server, sizeof(server));
  if (status != 0)
    resourceError(status, "client", "connect");

  /* ----Create a message---- */
  sprintf(buf, "Hello from client %d Server", id);
  printf("Client %d sending message: %s\n", id, buf);

  /* ----Send the message---- */
  nbytes = send(sock_1, buf, sizeof(buf), 0);
  if (nbytes < 0) 
    resourceError(nbytes, "client", "send");

  /* ----Receive reply---- */
  nbytes = recv(sock_1, buf, sizeof(buf), 0);
  if (nbytes < 0) 
    resourceError(nbytes, "client", "recv");

  printf("Client %d: returned message from server: %s\n", id, buf);

  /* ----Close socket and terminate---- */
  close(sock_1);
  printf("Client terminating\n");
  return 0;
}


