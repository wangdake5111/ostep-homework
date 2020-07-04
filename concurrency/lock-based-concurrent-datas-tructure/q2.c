#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include"common.h"
#include"common_threads.h"
typedef struct __counter_t {
int value;
pthread_mutex_t lock;
} counter_t;
typedef struct __myargs_t {
    int threads;
    counter_t* counter;
} myargs;
void init(counter_t *c) {
  c->value = 0;
  pthread_mutex_init(&c->lock, NULL);
}

void increment(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    c->value++;
    pthread_mutex_unlock(&c->lock);
 }

void decrement(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
 }
int get(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
 }
void* thread_function(void *args){
    myargs *arg = (myargs *)args;
    for(int i=0;i<1e6/arg->threads;i++){
        increment(arg->counter);
    }
    pthread_exit(EXIT_SUCCESS);
}
 int main(int argc, char* argv[]){
     if(argc != 2){
        fprintf(stderr, "there should be 2 arguments\n");
        exit(1);
    }
    int number = atoi(argv[1]);
    counter_t *ct = (counter_t *)malloc(sizeof(counter_t));
    init(ct);
    pthread_t threads[number];
    double start = GetTime();
    myargs *args = (myargs*)malloc(sizeof(args));
    args->counter = ct;
    args->threads = number;
    for(int i=0; i<number; i++){
        Pthread_create(&threads[i], NULL, thread_function,(void*)args);
    }
    for(int j=0; j<number; j++){
        Pthread_join(threads[j], NULL);
    }
    double end = GetTime();
    printf("time is %f\n", end-start);
    return 0;
 }