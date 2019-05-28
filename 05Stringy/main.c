#include <stdlib.h>
#include <stdio.h>
#include "work05.h"
#include <string.h>

//main method
int main(){
  char s1[] = "??W?";
  char s2[] = "hello";
  char s3[] = "goodbye";
  char s4[] = "";
  
  printf("s1: [%s]\n", s1);
  printf("s2: [%s]\n", s2);
  printf("s3: [%s]\n\n", s3);
  
  printf("Testing strlen(s2):\n");
  printf("[mine]: %d\n", mystrlen(s2));
  printf("[standard]: %ld\n\n", strlen(s2));
 
  printf("Testing strcpy(s1, s2):\n");
  printf("[mine]: %s\n", mystrcpy(s1, s2));
  printf("[standard]: %s\n\n", strcpy(s1, s2));
  
  printf("Testing strncpy(s1, s3, 3):\n");
  printf("[mine]: %s\n", mystrncpy(s1, s3, 3));
  printf("[standard]: %s\n\n", strncpy(s1, s3, 3));
  
  printf("Testing strcat(s1, s3):\n");
  printf("[mine]: %s\n", mystrcat(s1, s3));
  printf("[standard]: %s\n\n", strcat(s1, s3));
    
  printf("Testing strncat(s1, s2, 3):\n");
  printf("[mine]: %s\n", mystrncat(s1, s2, 3));
  printf("[standard]: %s\n\n", strncat(s1, s2, 3));
  
  printf("Testing strcmp\n");
  printf("Comparing ab to abc:\n");
  printf("[mine]: %d\n", mystrcmp("ab", "abc"));
  printf("[standard]: %d\n", strcmp("ab", "abc"));
  printf("Comparing abc to ab:\n");
  printf("[mine]: %d\n", mystrcmp("abc", "ab"));
  printf("[standard]: %d\n", strcmp("abc", "ab"));
  printf("Comparing abc to abc:\n");
  printf("[mine]: %d\n", mystrcmp("abc", "abc"));
  printf("[standard]: %d\n\n", strcmp("abc", "abc"));
  
  printf("Testing strncmp\n");
  printf("Comparing ab to abc, 2 bytes:\n");
  printf("[mine]: %d\n", mystrncmp("ab", "abc", 2));
  printf("[standard]: %d\n", strncmp("ab", "abc", 2));
  printf("Comparing ab to abc, 3 bytes:\n");
  printf("[mine]: %d\n", mystrncmp("ab", "abc", 3));
  printf("[standard]: %d\n\n", strncmp("ab", "abc", 3));
  
  printf("Testing strchr(s1, '1'):\n");
  printf("[mine]: %p\n", mystrchr(s1, '1'));
  printf("[standard]: %p\n\n", strchr(s1, '1'));
  
  printf("Testing strchr(s1, 0):\n");
  printf("[mine]: %p\n", mystrchr(s1, 0));
  printf("[standard]: %p\n\n", strchr(s1, 0));
  
  printf("Testing strchr(s2, 'l'):\n");
  printf("[mine]: %p\n", mystrchr(s2, 'l'));
  printf("[standard]: %p\n\n", strchr(s2, 'l'));

  return 0;
}
