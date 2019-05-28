#include <stdio.h>

//Problem 1

int mult35() {
  int i;
  int ans = 0;
  for (i = 1; i < 1000; i++) {
    if (i%3==0 || i%5==0) {
      ans += i;
    }
  }
  return ans;
}

//Problem 2

int fibNum(int n) {
  if (n == 1) {
    return 1;
  }
  else if (n == 2) {
    return 2;
  }
  else {
    return fibNum(n-1)+fibNum(n-2);
  }
}

int evenFib() {
  int i = 1;
  int ans = 0;
  while (fibNum(i) <= 4000000) {
    if (fibNum(i)%2 == 0) {
      ans += fibNum(i);
    }
    i++;
  }
  return ans;
}

/*Problem 3

int isPrime(int a) {
  int ans = 1;
  if (a < 2) {
    ans = 0;
  }
  else if (a > 2) {
    int i;
    for (i = 2; i < a; i++) {
      if (a%i != 0) {
	ans = 0;
      }
    }
  }
  return ans;
}

int primFact() {
  long ans = 600851475143;
  while (isPrime(ans) == 0) {
    int i;
    for (i = 2; i < ans; i++) {
      if (isPrime(i) == 1 && ans%i == 0) {
	ans = ans / i;
      }
    }
  }
  return ans;
}
*/

//Print

int main(){
  int a1 = mult35();
  int a2 = evenFib();
  //int a3 = primFact();
  printf("Problem 1: %d\n",a1);
  printf("Problem 2: %d\n",a2);
  //printf("Problem 3: %d\n",a3);
}
