#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t p = fork();
    if(p == 0){
        printf("Child: My process id is: %d\n", getpid());
        printf("Child: My parent's pid is: %d\n", getppid());
    }else{
        printf("Parent: My process id is: %d\n", getpid());
        printf("Parent: My child's pid is: %d\n", p);
    }
    return 0;
}