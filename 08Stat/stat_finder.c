#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <math.h>

int main(){

  printf("Finding file size:\n");

  struct stat storage;
  stat("thing.txt", &storage);

  int truesize = storage.st_size;

  int i = 0;

  while ((truesize % (int)pow(1024, i)) > 0){ //raises the power of 1024 to i
    i++;
  }

  float human_read = (truesize / (pow(1024, i)));

  char * size = malloc(2);

  if (i == 0){size = "B";};
  if (i == 1){size = "KB";};
  if (i == 2){size = "MB";};
  if (i == 3){size = "GB";};

  printf("File Size: %f%s\n", human_read, size);

  printf("\nFinding file permission:\n");

  int permissions = storage.st_mode % 511;

    /*
  char * perm = malloc(9);
    
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    if (permissions % 10 == 7){strcat("rwx", perm)};
    
    */
  
  printf("File permissions: %o\n", storage.st_mode % 511);

  printf("\nFinding last access times:\n");

  printf("Last access time: %s\n", ctime(&storage.st_atime));

  return 0;

}
