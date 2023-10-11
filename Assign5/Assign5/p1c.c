#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void parent() {
	int n = 1000;
	printf("This is parent with process id %d. Sleeping for %d seconds.\n", getpid(), n);
	sleep(n);
	printf("Parent with process id %d exiting...\n", getpid());
	exit(n);
}

void child(){
	int n = 5;
	printf("This is child with process id %d. Sleeping for %d seconds.\n", getpid(), n);
	sleep(n);
	printf("Child with process id %d exiting...\n", getpid());
	exit(n);
}

void grandchild(){
	int n = 10;
	printf("This is grandchild with process id %d. Sleeping for %d seconds.\n", getpid(), n);
	sleep(n);
	printf("Grandchild with process id %d exiting...\n", getpid());
	exit(n);
}

void catch(int snum) {
	int pid;
	int status;
	pid = wait(&status);
	printf("process pid=%d exited with value %d\n",pid, WEXITSTATUS(status));
}

int main(){
	
	signal(SIGCHLD, catch);
	
	if(fork() == 0){
		if(fork() == 0){
			// grandchild
			grandchild();
		}
		else{
			// child
			child();
		}
	}
	else{
		// parent
		parent();
	}
	
	return 0;
}

/* if child terminates before the grand child, then the grand child becomes an orphan. Then the grandchild is adopted by the init process.
If the grand child terminates earlier, then the child also exits with it. */
