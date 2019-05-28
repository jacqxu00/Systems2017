#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int random_gen(){

  int r;

  r = open("/dev/random", O_RDONLY);

  int n;

  read(r, &n, 4);

  close(r);

  return n;
  

}

int main(){

  //int t = random_gen();

  //printf("result: %d\n", t);

  int arr[10];

  int i = 0;

  for (; i < 10; i++){

    arr[i] = random_gen();
    printf("random %d: %d\n", i, arr[i]);

  }

  int r;
  int w;

  w = open("target_file", O_CREAT | O_WRONLY, 0666);
  write(w, arr, sizeof(arr));
  close(w);
  
  r = open("target_file", O_RDONLY, 0666);
  
  int arr2[10];

  read(r, arr2, sizeof(arr));

  i = 0;

  printf("\nCONTENTS OF ARR2:\n\n");
  
  for (; i < 10; i++){

    printf("arr2[%d]: %d\n", i, arr2[i]);

  }

  close(r);

  return 0;

}
