#include <string.h>

//start of functions
int mystrlen( char *source ) {
  int i = 0;
  while (*source){
    i++;
    source++;
  }
  return i;
}
	
char * mystrcpy( char *dest, char *source ){
  int i;
  for (i = 0; source[i]; i++){
    dest[i] = source[i];
  }
  dest[strlen(dest) + i] = '\0';
  return dest;
}

char * mystrncpy( char *dest, char *source, int n ){
  int i;
  for (i = 0; source[i] && i < n; i++){
    dest[i] = source[i];
  }
  dest[strlen(dest) + i] = '\0';
  return dest;
}

char * mystrcat( char *dest, char *source ) {
  char variable[strlen(dest)+strlen(source)];
  char *temp = variable;
  strcpy(temp, dest);
  int i;
  for (i = 0; source[i]; i++) {
    temp[strlen(dest)+i] = source[i];
  }
  temp[strlen(dest) + i] = '\0';
  return temp;
}

char * mystrncat( char *dest, char *source, int n) {
  char variable[strlen(dest)+n];
  char *temp = variable;
  strcpy(temp, dest);
  int i;
  for (i = 0; source[i] && i < n; i++) {
    temp[strlen(dest)+i] = source[i];
  }
  temp[strlen(dest) + i] = '\0';
  return temp;
}

int mystrcmp( char *s1, char *s2 ){
  int i;
  for (i = 0; s1[i] || s2[i]; i++){
    if (s1[i] != s2[i]) return s1[i] - s2[i];
  }
  return 0;
}

int mystrncmp( char *s1, char *s2, int n ){
  int i;
  for (i = 0; i < n && (s1[i] || s2[i]); i++){
    if (s1[i] != s2[i]) return s1[i] - s2[i];
  }
  return 0;
}

char * mystrchr( char *s, char c ){
  while (*s){
    if (*s == c) return s;
    s++;
  }
  if (c == 0) return s;
  return 0;
}
