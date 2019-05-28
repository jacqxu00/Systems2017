#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>

#define KEY 45279

void create(int n){
  int desc = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0664);
	if (desc == -1) {
		printf("semaphore already exists\n");
		return;
	}
	semctl(desc, 0, SETVAL, n);
  printf("semaphore created: %d\n", desc);
	printf("semaphore value: %d\n", n);
}

int view(){
	int sd = semget(KEY, 1, 0664);
	return semctl(sd, 0, GETVAL);
}

int remove_sem(){
	int sd = semget(KEY, 1, 0664);
	return semctl(sd, 0, IPC_RMID);
}

int main(int argc, char ** argv){

  int sem;
	
  if (strcmp(argv[1], "-c") == 0){
		create(atoi(argv[2]));
  }
  else if (strcmp(argv[1], "-v") == 0){
		sem = view();
    printf("semaphore value: %d\n", sem);
  }
  else if (strcmp(argv[1], "-r") == 0){
		sem = remove_sem();
    printf("semaphore removed: %d\n", sem);
  }
	else {
		printf("please input correct arguments\n");
	}

  return 0;
}

