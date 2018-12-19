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
  char *wkpbf = malloc(HANDSHAKE_BUFFER_SIZE);
  printf("");
  read(wkpfd, wkpbf, HANDSHAKE_BUFFER_SIZE);
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
  char entr[HANDSHAKE_BUFFER_SIZE];
  
  return 0;
}
