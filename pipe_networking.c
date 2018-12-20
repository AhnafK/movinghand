#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  mkfifo("wkp",0600);
  printf("Made wkp\n");
  int wkpfd = open("wkp",O_RDONLY|O_CREAT,0600);
  if(wkpfd == -1){
    printf("failure\n");
    return -1;
  }
  char ppname[HANDSHAKE_BUFFER_SIZE];
  read(wkpfd, ppname, HANDSHAKE_BUFFER_SIZE);
  printf("recieved %s\n", ppname);
  int pp = open(ppname,O_WRONLY);
  printf("%s",ppname);
  char sresp[HANDSHAKE_BUFFER_SIZE] = "SERVER";
  write(pp, sresp, HANDSHAKE_BUFFER_SIZE);
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
  int wkpfd = open("wkp",O_RDONLY);
  printf("Client connected to wkp\n");
  char entr[HANDSHAKE_BUFFER_SIZE] = "pp";
  mkfifo("pp",0644);
  write(wkpfd, entr,HANDSHAKE_BUFFER_SIZE);
  int pp = open("pp", O_RDONLY);
  char response[HANDSHAKE_BUFFER_SIZE];
  read(pp, response, HANDSHAKE_BUFFER_SIZE);
  printf("%s", response);
  return 0;
}
