#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  printf("started server\n");
  int fifO = mkfifo("mario", 0644);
  printf("created " );
  int wkp = open("mario", O_RDONLY);
  printf("and opened well known pipe\n");
  //if(fifO == -1){
  //  printf("failure\n");
  //  return -1;
  //}
  char buffer[HANDSHAKE_BUFFER_SIZE];
  read(wkp, buffer, HANDSHAKE_BUFFER_SIZE);
  printf("recieved %s\n", buffer);
  int pp = open(buffer,O_WRONLY);
  printf("%s",buffer);
  char sresp[HANDSHAKE_BUFFER_SIZE] = "SERVER";
  write(pp, sresp, HANDSHAKE_BUFFER_SIZE);
  close(wkp);
  close(pp);
  printf("done\n");
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
  int wkpfd = open("mario",O_WRONLY);
  printf("Client connected to wkp\n");
  char entr[HANDSHAKE_BUFFER_SIZE] = "pp";
  mkfifo("pp",0644);
  write(wkpfd, entr,HANDSHAKE_BUFFER_SIZE);
  int pp = open("pp", O_RDONLY);
  char response[HANDSHAKE_BUFFER_SIZE];
  read(pp, response, HANDSHAKE_BUFFER_SIZE);
  printf("%s\n", response);
  return 0;
}
