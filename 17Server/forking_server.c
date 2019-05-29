#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);

  int parent;
  int from_client;
  char buffer[BUFFER_SIZE];
  
  while(1){
    //handshake
    from_client = server_setup();
    //should be after msg received
    //perhaps connections made in server_setup(), then copied over
    parent = fork();
    if(parent){
      
    }else{
      subserver(from_client);
    }
  }
  
  return 0;
}

void subserver(int from_client) {
  char buffer[BUFFER_SIZE];
  int to_client = server_connect(from_client);
  while(read(from_client, buffer, sizeof(buffer))){
    process(buffer);
    write(to_client, buffer, sizeof(buffer));
  }
}

void process(char * s) {
  while(*s){
    *s = toupper((unsigned char)*s);
    s++;
  }
}
