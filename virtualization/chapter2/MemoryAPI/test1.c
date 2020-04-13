#include <stdio.h>
#include <stdlib.h>

int main(){
    char *str = "hello";
    int *x = (int *)malloc(10*sizeof(int));
    printf("%d\n",sizeof(x));
    printf("%d\n",strlen(str)+1);
}