#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include"common.h"
#include"common_threads.h"
#define ALL_WORK 1e6
int THREADS;
typedef struct __node_t {
    pthread_mutex_t lock;
    int value;
    struct __node_t *next;
} node_t;
typedef struct __scaling_linked_list_t_ {
    node_t *start;
    node_t *end;
} slList;
typedef struct __myargs_t {
    slList *list;
    int value;
    int task;
} myargs;
void List_Init(slList* list){
    node_t *start = (node_t*) malloc(sizeof(node_t));
    if(start==NULL){
        perror("malloc");
        return;
    }
    pthread_mutex_init(&start->lock, NULL);
    start->next = NULL;
    start->value = 1e6;
    list->end = list->start = start;
}
void List_Insert(slList *list,int value){
    // printf("in insert\n");
    node_t *next = (node_t*)malloc(sizeof(node_t));
    if(next==NULL){
        perror("malloc");
        return;
    }
    next->value=value;
    pthread_mutex_init(&next->lock, NULL);
    next->next=NULL;
    // printf("error1\n");
    node_t *tmp = list->start;
    pthread_mutex_lock(&tmp->lock);
    //pthread_mutex_lock(&tmp->next->lock);
    next->next = list->start->next;
    list->start->next = next;
    pthread_mutex_unlock(&tmp->lock);
    // if(tmp->next == NULL){
    //     pthread_mutex_t *lock = &tmp->lock;
    //     list->end->next = next;
    //     list->end = list->end->next;
    //     pthread_mutex_unlock(lock);
    // }else{
    //     while(1){
    //         pthread_mutex_t *lock = &tmp->lock;
    //         if(tmp->next == NULL){
    //             tmp->next = next;

    //             pthread_mutex_unlock(&tmp->lock);
    //             //printf("out\n");
    //             break;
    //         }
    //         pthread_mutex_lock(&(tmp->next->lock));
    //         tmp = tmp->next;
    //         pthread_mutex_unlock(lock);
    //     }
    // }
    // printf("error2\n");
    // printf("error3\n");
    // printf("error4\n");
    // printf("error5\n");

    // printf("error6\n");

 
}
int get(slList *list, int value){
    //printf("in get");
    node_t *tmp = list->start;
    pthread_mutex_lock(&(tmp->lock));
    while(1){
        pthread_mutex_t *lock = &(tmp->lock);
        if(tmp->next == NULL){
            pthread_mutex_unlock(lock);
            return 0;
        }
        if(tmp->value==value){
            pthread_mutex_unlock(lock);
            return 1;
        }
        pthread_mutex_lock(&tmp->next->lock);
        tmp = tmp->next;
        pthread_mutex_unlock(lock);
    }
}
void printList(slList *list){
    node_t *tmp = list->start;
    while(tmp->next != NULL){
        printf("the value is %d\n", tmp->value);
        tmp = tmp->next;
    }
    return;
}

void *thread_func(void *args){
    myargs *arg = (myargs*)args;
    for(int i=0;i<ALL_WORK/THREADS; i++){
        List_Insert(arg->list, arg->value);

        // if(arg->task==0){
        //     get(arg->list, rand());
        // }
        // else
        //     List_Insert(arg->list, arg->value);
    }
    return NULL;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "there should be 2 arguments\n");
        exit(1);
    }
    THREADS = atoi(argv[1]);
    slList *list = (slList*)malloc(sizeof(slList));
    List_Init(list);
    pthread_t threads[THREADS];
    double start = GetTime();
    
    for(int i=0; i<THREADS; i++){
        myargs *args = (myargs*)malloc(sizeof(myargs));
        args->list = list;
        args->value = rand();
        //printf("the number is %d\n", args->value);
        if(i%2==0)
            args->task = 1;
        else
            args->task = 0;
        pthread_create(&threads[i], NULL, thread_func, (void*)args);
    }
    for(int i=0; i<THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    double end = GetTime();
    printf("time is %f\n", end-start);
    // printList(list);
    free(list);
    return 0;

}
