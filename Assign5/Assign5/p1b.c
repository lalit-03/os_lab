#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int n_proc = 0;

void child(int n){
	printf("This is child %d with process id %d. Sleeping for %d seconds.\n", n, getpid(), n);
	sleep(n);
	printf("Child %d with process id %d exiting...\n", n, getpid());
	exit(n);
}

void catch(int snum) {
	int pid;
	int status;
	pid = wait(&status);
	printf("parent: child process pid=%d exited with value %d\n",pid, WEXITSTATUS(status));
	n_proc--;
}

int main(int argc, const char *argv[]){

	int NUM_CHILD = atoi(argv[1]);
	
	signal(SIGCHLD, catch);
	
	for(int i=0;i<NUM_CHILD;i++){
		if(fork() == 0){
			child(i);
		}
		else{
			n_proc++;
		}
	}
	
	while(n_proc!=0){
//		printf("parent here\n");
		sleep(1000);
	}
	printf("parent exiting...\n");
	
	return 0;
}
