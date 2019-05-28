#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char ** argv){
  char cmd = action(argc, argv);

  int shm_d;
  int * mem_seg_p; //pointer to location of mem seg (the int)
  int sem_d;
  int f_d;
  create_set(&shm_d, &mem_seg_p, &sem_d, &f_d); //each process/every time it is run, will need access to these

  //printf("sem_d: %d value: %d \n", sem_d, semctl(sem_d, 0, GETVAL));

  if(cmd == 'c'){

    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = -1; //Down b/c about to access shm
    sem_buf.sem_flg = SEM_UNDO;
    semop(sem_d, &sem_buf, 1); //should block until sem is not 0
    
    //prints previous line
    printf("\nPrevious Line: \n");
    lseek(f_d, (*mem_seg_p) * -1, SEEK_END);
    char * line = (char *)calloc(1, *mem_seg_p + 1);
    int reader = read(f_d, line, *mem_seg_p);
    printf("%s \n\n", line);
    free(line);

    //asks user for new input line
    char new_line[1000];
    printf("Enter New Line: \n");
    fgets(new_line, sizeof(new_line), stdin);
    *mem_seg_p = strlen(new_line);
    lseek(f_d, 0, SEEK_END);
    write(f_d, new_line, strlen(new_line));
		
		
    shmdt(mem_seg_p);
    //Up sem at end
    sem_buf.sem_op = 1;
    semop(sem_d, &sem_buf, 1);
		
  }else if(cmd == 'r'){

    printf("\n");
    //block until sem available
    struct sembuf sem_buf;
    sem_buf.sem_num = 0;
    sem_buf.sem_op = -1;
    semop(sem_d, &sem_buf, 1); //should block until sem is not 0
    rm(shm_d, &mem_seg_p, sem_d, f_d);

  }else if(cmd == 'v'){
		
    printf("\n");
    view(f_d);

  }
  return 0;
}
