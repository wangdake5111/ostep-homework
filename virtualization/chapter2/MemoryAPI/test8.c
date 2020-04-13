#include<stdlib.h>
#include <stdio.h>
struct vector {
    int *data;
    int size;
    int capacity;
};
struct vector * init(){
    struct vector * vec = (struct vector *)malloc(sizeof(struct vector));
    vec->capacity = 2;
    vec->data = (int*)malloc(vec->capacity*sizeof(int));
    vec->size = 0;
    return vec;
}
void addAnEntry(struct vector * vec, int data){
    if(vec->size  == vec->capacity){
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity*sizeof(int));
    }
    (vec->data)[vec->size++] = data;
}
void delAnEntry(struct vector * vec){
    (vec->data)[--(vec->size)] = 0;
    if(vec->size == (int)(vec->capacity/4)){
        vec->capacity /= 2;
        vec->data = (int*)realloc(vec->data, vec->capacity*sizeof(int));
    }
}
void freeVec(struct vector * vec){
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;
}
void printVec(struct vector * vec){
    printf("the data is : \n");
    for(int i=0;i<vec->size;i++){
        printf("%d\t", (vec->data)[i]);
    }
    printf("\n");
    printf("the size is %d, the capacity is %d\n", vec->size, vec->capacity);
}
int main(){
    struct vector *vec = init();
    printVec(vec);
    addAnEntry(vec, 1);
    addAnEntry(vec, 10);
    addAnEntry(vec,30);
    printVec(vec);
    delAnEntry(vec);
    printVec(vec);
    freeVec(vec);
    return 0;

}