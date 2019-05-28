#include "pipe_networking.h"

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("server has been interrupted \n");
    remove("upstream_pipe");
    exit(0);
  }
}

void toupper_str(char * str){
  while(*str){
    *str = toupper((unsigned char)*str);
    str++;
  }
}

int main() {
  signal(SIGINT, sighandler);

  int to_client;
  int from_client;
  
  char buffer[BUFFER_SIZE];

  while(1){
    from_client = server_handshake( &to_client );

    while(read(from_client, buffer, sizeof(buffer))){
      toupper_str(buffer);
      write(to_client, buffer, sizeof(buffer));
    }
  }
  
  return 0;
}
