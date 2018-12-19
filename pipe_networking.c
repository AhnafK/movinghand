#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  mkfifo("wkp",0644);
  int wkpfd = open("wkp",O_RDONLY);
  char ppname[HANDSHAKE_BUFFER_SIZE];
  printf("Connecting to:\t");
  read(wkpfd, ppname, HANDSHAKE_BUFFER_SIZE);
  int pp = open(pp,O_WRONLY);
  printf("%s",ppname);
  char sresp[HANDSHAKE_BUFFER_SIZE] = "SERVER";
  write(pp, sresp, HANDSHAKE_BUFFER_SIZE);
  return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int wkpfd = open("wkp",O_RDONLY);
  char entr[HANDSHAKE_BUFFER_SIZE] = "pp";
  mkfifo("pp",0644);
  write(wkpfd, entr,HANDSHAKE_BUFFER_SIZE);
  int pp = open("pp", O_RDONLY);
  char response[HANDSHAKE_BUFFER_SIZE];
  read(pp, response, HANDSHAKE_BUFFER_SIZE);
  return 0;
}
