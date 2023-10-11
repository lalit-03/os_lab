#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle(int signum){
    pid_t p = wait(NULL);
    printf("Child with pid %d having %d as a parent has exited.\n",p,getpid());
}

int main(){
    signal(SIGCHLD, handle);
    printf("Parent PID: %d\n", getpid());
    pid_t child = fork();
    if(child == 0){
        printf("Child PID: %d\n", getpid());
        pid_t grandchild = fork();
        if(grandchild == 0){
            printf("Grandchild PID: %d\n", getpid());
            sleep(2);
            printf("Grandchild's current parent is: %d\n", getppid());
        }else{
            sleep(1);
        }
    }else{
        char k;
        scanf("%s",&k);
    }
}