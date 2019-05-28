// Jackie Xu
// Systems
// Period 4
// 09/28

#include <stdio.h>
#include <string.h>

int main() {
  
  //strcat(str1,str2)
  //concatenates str2 to str1
  char str[100];
  char *greeting = "Hello there, ";
  char *name = "friends.";
  strcpy(str,greeting);
  
  printf("1: %s \n",str); //Hello there,
  strcat(str,name);
  printf("2: %s \n",str); //Hello there, friends.
  printf("Greeting: %s \n",greeting);
  printf("Name: %s \n\n",name);

  //strncat(str1,str2,numchars)
  //concatenates numchars of str2 to str1
  char str1[100];
  strcpy(str1,greeting);

  printf("1: %s \n",str1); //Hello there,
  strncat(str1,name,3);
  printf("2: %s \n",str1); //Hello there, fri
  
  return 0;
}
