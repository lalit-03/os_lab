#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t p = fork();
    if(p == 0){
        printf("Child: My process id is: %d\n", getpid());
        printf("Child: My parent's pid is: %d\n", getppid());
        exit(0);
    }else{
        wait(NULL);
        printf("Parent: My process id is: %d\n", getpid());
        printf("Parent: My child's pid is: %d\n", p);
        printf("Parent: Child with pid %d has been successfully terminated.\n", p);
    }
    return 0;
}