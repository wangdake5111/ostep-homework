#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork error");
        exit(1);
    } else if(pid == 0){
        char *myargs[2];
        // myargs[0] = strdup("/bin/ls");
        // myargs[1] = NULL;
        // int r = execv(myargs[0], myargs);
        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        int r = execvp(myargs[0], myargs);
    }else{
        printf("parent\n");

    }
    return 0;
}