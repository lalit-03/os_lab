#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle(int signum){
    pid_t p = wait(NULL);
    printf("Child with PID %d has exited with parent %d.\n",p, getpid());
}
int main(int argc, char** argv){
    signal(SIGCHLD, handle);
    int n = atoi(argv[1]);
    pid_t parent = getpid();
    for(int i=0;i<n;i++){
        if(getpid() != parent)break;
        sleep(1);
        fork();
    }
    if(getpid() != parent){
        sleep(0);
    }else{
        char k;
        scanf("%s",&k);
    }
}