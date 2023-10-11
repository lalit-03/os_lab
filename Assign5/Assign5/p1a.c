#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigintHandler(int sig_num){
    printf("\nSIGINT Handler\n");
    printf("Do you really want to terminate(y/n): ");
    char input = 'x';
    scanf("%c", &input);
    if(input == 'y'){
    	printf("Terminating program....\n");
    	exit(0);
    }
    else{
    	printf("Continuing execution..\n");
    }
}

void sigtermHandler(int sig_num){
    printf("\nSIGTERM Handler");
    printf("\n Do you really want to terminate(y/n): ");
    char input = 'x';
    scanf("%c", &input);
    if(input == 'y'){
    	printf("Terminating program....\n");
    	exit(0);
    }
    else{
    	printf("Continuing execution..\n");
    }
}

int main(){
	printf("Process ID: %d\n", getpid());

	signal(SIGINT, sigintHandler);
	signal(SIGTERM, sigtermHandler);
	
	while(1){}
	
	return 0;
}
