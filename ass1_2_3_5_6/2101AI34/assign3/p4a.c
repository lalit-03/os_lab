#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char ** argv){
    FILE* f = fopen(argv[1], "w");
    pid_t p = fork();
    if(p == 0){
        fputs("I am the child processs.\n",f);
    }else{
        fputs("I am the parent process.\n",f);
        wait(NULL);
        printf("Child process with pid %d has exited.", p);
    }
    return 0;
}