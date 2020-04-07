#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main(){
    int fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC);
    write(fd, "initialize\n", strlen("initialize\n"));
    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr, "fork error");
        exit(1);
    }else if(pid == 0){
        char *c = "child11111111111111\n";
        write(fd, c, strlen(c));
    }else {
        char *c = "parent1111111111111\n";
        write(fd, c, strlen(c));
    }
    close(fd);
    return 0;
}