#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int x = 100;
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(pid == 0){
        x = 10;
        printf("child x :%d\n",x);
    }else {
        wait(NULL);
        printf("parent x :%d\n",x);
    }
    return 0;
}