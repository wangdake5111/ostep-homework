#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data = (int *)malloc(sizeof(int));
    free(data);
    printf("%d\n", data[2]);
    return 0;
}