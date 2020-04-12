#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "there should be 2 arguments\n");
        exit(1);
    }
    int size = atoi(argv[1])*1000000;
    printf("pid is %d\n", getpid());
    char *array;
    array = (char *)malloc(size * sizeof(char));
    while(1){
        for(int i=0;i<size;i++){
            array[i] = i+3;
        }
    }
    return 0;

}