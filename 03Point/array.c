#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int a[], int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("arr[%d]: %d\n",i,a[i]);
  }
}

int main() {
  srand(time(NULL));
  int a[10];
  int i;
  for (i = 0; i < 9; i++) {
    a[i] = rand();
  }
  a[9] = 0;
  
  printf("The original array: \n");
  print_array(a,10);

  int b[10];
  int *c = a;
  for (i = 9; i >= 0; i--) {
    b[i] = *c;
    c++;
  }

  printf("The second array: \n");
  print_array(b,10);

  return 0;
}
	
