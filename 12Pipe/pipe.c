#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){

    int f, READ = 0, WRITE = 1;
	int random;
	
	int fds1[2];
	int fds2[2];
	pipe(fds1);
	pipe(fds2);
		
    f = fork();

    if (f){

       	close(fds1[READ]);
		close(fds2[WRITE]);
		
		srand(time(NULL));
		random = rand();
		random = random % 10;
		
		printf("[parent] sending: %d\n", random);
		write(fds1[WRITE],&random,sizeof(random));
		
		int ans;
		read(fds2[READ], &ans, sizeof(fds2[READ]));
		
		printf("parent] received: %d\n", ans);
		
    }

    else{

        close(fds1[WRITE]);
		close(fds2[READ]);
		
		int num;
		read(fds1[READ], &num, sizeof(fds1[READ]));
		printf("[child] doing maths on: %d\n", num);
		
		num = num*num;
		write(fds2[WRITE], &num, sizeof(num));

    }
	
	return 0;

}
