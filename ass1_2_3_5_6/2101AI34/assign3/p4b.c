#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char ** argv){
    close(0);
    FILE* f = fopen(argv[1],"r");
    pid_t p = fork();
    if(p == 0){
        char * args[] = {"./mycat", NULL};
        execv("./mycat", args);
    }else{
        wait(NULL);
    }
}