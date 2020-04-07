#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main(){
    int pipeend[2];
    pid_t pids[2];
    char buf;
    if(pipe(pipeend) == -1){
        perror("pipe error: ");
    }
    pids[0] = fork();
    if(pids[0] < 0){
        fprintf(stderr, "fork error");
        exit(1);
    }else if(pids[0] == 0){
        close(pipeend[0]);
        char str[] = "pipe test";
        write(pipeend[1], str, strlen(str));
        close(pipeend[1]);
        waitpid(pids[1], NULL, 0);
    }else{
        pids[1] = fork();
        if(pids[1] < 0){
        fprintf(stderr, "fork error");
        exit(1);
    }else if(pids[1] == 0){
        close(pipeend[1]);
        while(read(pipeend[0], &buf, 2)){
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipeend[0]);
    }else{
        ;
    }
    }
    return 0;
}