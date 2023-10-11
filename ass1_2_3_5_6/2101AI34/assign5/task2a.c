#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void confirm(int signum){
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    printf("You're sure yo wanna exit? y/n\n");
    char k;
    scanf("%s",&k);
    if(k == 'y') exit(0);
    else{
        signal(SIGINT, confirm);
        signal(SIGTERM, confirm);
    }
}

int main(){
    signal(SIGINT, confirm);
    signal(SIGTERM, confirm);
    while(1)sleep(1);
    return 0;
}