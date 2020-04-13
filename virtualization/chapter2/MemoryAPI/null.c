#include <stdlib.h>
#include <stdio.h>

int main(){
    int *x = (int *)malloc(sizeof(int));
    x = NULL;
    int y = *x;
    free(x);
    return 0;
}