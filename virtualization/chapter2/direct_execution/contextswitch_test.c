/*
linux
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sched.h>
#define LOOP 1000000
int main(){
    struct timeval start, end;
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    int pipe1[2], pipe2[2];
    if(pipe(pipe1)==-1 || pipe(pipe2)==-1){
        perror("pipe");
        exit(1);
    }
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }else if (pid == 0){
        if(sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1){
            perror("sched");
            exit(1);
        }
        for(int i=0; i<LOOP; i++){
            read(pipe1[0], NULL, 0);
            write(pipe2[1], NULL, 0);
        }
    }else {
        if(sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) == -1){
            perror("sched");
            exit(1);
        }
        gettimeofday(&start, NULL);
        for(int i=0; i<LOOP; i++){
            read(pipe1[1], NULL, 0);
            write(pipe2[0], NULL, 0);
        }
        gettimeofday(&end, NULL);
        double diff = ((double)end.tv_sec*1e6 + (double)end.tv_usec) -
                ((double)start.tv_sec*1e6 + (double)start.tv_usec);
        printf("microsecond per context switch: %.10f\n", diff/(2*LOOP));
    }
    return 0;
}