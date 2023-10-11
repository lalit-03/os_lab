#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t p = fork();
    if(p == 0){
        char * args[] = {"./mycat", NULL};
        execv("./mycat", args);
    }else{
        printf("Hello from parent process\n");
        wait(NULL);
    }
}