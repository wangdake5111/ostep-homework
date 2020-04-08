#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

#define LOOP 10000000

int main(){
    struct timeval time1, time2;
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork error");
        exit(1);
    }else if (pid == 0){
        int r1 = gettimeofday(&time1, NULL);
        for(int i=1;i<LOOP;i++){
            read(STDIN_FILENO, NULL, 0);
            //printf("error");
            int r2 = gettimeofday(&time2, NULL); 
        }
        double diff = ((double)time2.tv_sec * 1e6 + (double)time2.tv_usec) -
        ((double)time1.tv_sec * 1e6 + (double)time1.tv_usec);
        printf("the microseconds per syscall = %.10f\n", diff/LOOP);
    }else {
        wait(NULL);
    }
} 