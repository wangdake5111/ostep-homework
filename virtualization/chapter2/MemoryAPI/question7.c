#include <stdlib.h>

int main(){
    int *data = (int*) malloc(sizeof(int)*100);
    free(&data[2]);
    return 0;
}