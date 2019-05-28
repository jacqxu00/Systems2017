#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>

#define KEY 51062

union semun{
  int val;
  struct semid_ds * buf;
  unsigned short * array;
  struct seminfo * _buf;
};

//for error testing
char action(int argc, char ** argv){
  if(argc >= 2){
    if(strcmp(argv[1], "-c") == 0){
      return 'c';
    }else if(strcmp(argv[1], "-r") == 0){
      return 'r';
    }else if(strcmp(argv[1], "-v") == 0){
      return 'v';
    }else{
      printf("invalid flag \n");
      exit(0);
      return 0;
    }
  }else{
    printf("flag needed \n");
    exit(0);
    return 0;
  }
  return 0; //in case
}

//display full contents of story
int view(int f_d){ 
  int file_size = lseek(f_d, 0, SEEK_END);
  lseek(f_d, 0, SEEK_SET);
  char * contents = (char *)calloc(1, file_size);
  //read(f_d, &contents, file_size);
  read(f_d, contents, file_size);
  printf("Full Story: \n%s \n", contents);

  return 0;
}

int create_set(int * shm_d_p, int ** mem_seg_p_p, int * sem_d_p, int * f_d_p){
  
  //create shared memory (to hold size of last line written to file)
  *shm_d_p = shmget(KEY, sizeof(int), IPC_CREAT | 0600);
	
  //if new mem seg, val is automatically set to 0
  *mem_seg_p_p = shmat(*shm_d_p, 0, 0);
  

  //create semaphore
  int temp_sem_d = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
  *sem_d_p = semget(KEY, 1, IPC_CREAT | 0600);
  if(temp_sem_d != -1){ //if sem does not already exist
    union semun arg;
    arg.val = 1;
    semctl(*sem_d_p, 0, SETVAL, arg);
  }
  
  //create file
  *f_d_p = open("story.txt", O_APPEND | O_RDWR | O_CREAT, 0644);

  return 0;
	
}

//when semaphore available (check in main before calling rm())
int rm(int shm_d, int ** mem_seg_p_p, int sem_d, int f_d){ 
	
  //remove shared memory
  shmdt(*mem_seg_p_p); //detach seg from variable
  *mem_seg_p_p = NULL;
  struct shmid_ds mdata;
  shmctl(shm_d, IPC_RMID, &mdata);

  //remove semaphore
  semctl(sem_d, 0, IPC_RMID);

  //display full contents of story
  view(f_d);

  //remove story
  //could erase/overwrite contents
  close(f_d);
  execlp("rm", "rm", "story.txt", NULL);

  return 0;
}
