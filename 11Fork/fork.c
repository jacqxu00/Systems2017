#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int f, random, status, child;

    printf("Starting to fork\n");
    f = fork();
    if (f){
        f = fork();
    }

    if (f){

        child = wait(&status);

        unsigned char * seconds = (unsigned char *) &status + 1;

        printf("child %d finished first, with %d wait time\n", child, *seconds);

        printf("parent process completed, exiting now\n");

        return 0;

    }

    else{

        printf("I'm a child! My pid is: %d\n", getpid());

        srand( getpid());

        random = rand();
        random = random % 15;
        random += 5;

        printf("I'm waiting for %d seconds\n\n", random);

        sleep(random);

        printf("I, child number %d, am awoken\n", getpid());

        return random;

    }

}
