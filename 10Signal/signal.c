#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


static void sighandler (int signo) {
	if (signo == SIGINT) {
		int fd = open("sigint.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		char message[29] = "Program exited due to SIGINT\n";
		write(fd, message, sizeof(message)-1);
		close(fd);
		exit(SIGINT);
	}
	if (signo == SIGUSR1) {
		printf("Parent PID: %d\n", getppid());
	}
}

int main () {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	while (1) {
		printf("PID: %d\n", getppid());
		sleep(1);
	}
}
