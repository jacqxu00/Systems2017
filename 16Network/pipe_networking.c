#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {

  int fd_d;
  int fd_u;

  //create public FIFO
  //mkfifo("downstream_pipe", 0600);
  mkfifo("upstream_pipe", 0600);

  //open public FIFO for reading
  //fd_d = open("downstream_pipe", O_WRONLY);
  fd_u = open("upstream_pipe", O_RDONLY);

  //read from public FIFO
  char msg[HANDSHAKE_BUFFER_SIZE];
  printf("[server] from [client]: \n");
  read(fd_u, msg, sizeof(msg));
  printf("\t %s \n", msg);

  //remove WKP
  remove("upstream_pipe");

  //open private FIFO
  fd_d = open(msg, O_WRONLY);
	
  //write to private FIFO
  //probably better to send back a different msg
  printf("[server] to [client]: \n");
  //char msg1[256] = "temp msg from server";
  //write(fd_d, msg1, strlen("temp msg from server"));
  //printf("\t %s \n", msg1);
  write(fd_d, msg, sizeof(msg));
  printf("\t %s \n", msg);

  //server receives msg/confirmation
  printf("[server] from [client]: \n");
  read(fd_u, msg, sizeof(msg));
  printf("\t %s \n", msg);

  //close(fd_d);
  //close(fd_u);
  *to_client = fd_d;
  return fd_u;

}


/*=========================
  client_handshake
  args: int * to_server

  Perofrms the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  
  int fd_d;
  int fd_u;

  //create private FIFO
  //create unique name for private FIFO using pid
  char msg[HANDSHAKE_BUFFER_SIZE];
  sprintf(msg, "%d", getpid());
  mkfifo(msg, 0600);

  //open public FIFO for writing
  //fd_d = open("downstream_pipe", O_RDONLY);
  fd_u = open("upstream_pipe", O_WRONLY);
  
  if(fd_u == -1){
    printf("server currently unavailable \n");
    remove(msg);
    exit(0);
  }else{
    //client sends msg to server and waits for response
    //char msg[256] = "temp msg from client";
    printf("[client] to [server]: \n");
    write(fd_u, msg, sizeof(msg));
    printf("\t %s \n", msg);

    //open private FIFO for reading
    fd_d = open(msg, O_RDONLY);

    //read reply from private FIFO	
    printf("[client] from [server]: \n");
    //int len = read(fd_d, msg, sizeof(msg));
    //printf("\t length of read: %d\n", len);
    read(fd_d, msg, sizeof(msg));
    printf("\t %s \n", msg);

    //remove private FIFO
    remove(msg);
	
    printf("[client] to [server]: \n");
    //char msg1[256] = "msg received by client";
    //write(fd_u, msg1, sizeof("msg received by client"));
    //printf("\t %s \n", msg1);
    write(fd_u, ACK, sizeof(ACK));
    printf("\t %s \n", ACK);

    //close(fd_d);
    //close(fd_u);
    *to_server = fd_u;
    return fd_d;
  }
}
