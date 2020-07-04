#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include"common.h"
#define NUMCPUS 1
#define THREADSEACHCPU 1
typedef struct __counter_t {
    int global; // global count
    pthread_mutex_t glock; // global lock
    int local[NUMCPUS]; // per-CPU count
    pthread_mutex_t llock[NUMCPUS]; // ... and locks
    int threshold; // update frequency
} counter_t;
typedef struct __myargs_t {
    counter_t* ct;
    int threads;
    int amt;
    int thre;
    int threadid;
} myargs;

// init: record threshold, init locks, init values
 // of all local counts and global count
 void init(counter_t *c, int threshold) {
    c->threshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    int i;
    for (i = 0; i < NUMCPUS; i++) {
    c->local[i] = 0;
    pthread_mutex_init(&c->llock[i], NULL);
    }
 }

 // update: usually, just grab local lock and update
 // local amount; once local count has risen ’threshold’,
 // grab global lock and transfer local values to it
 void update(counter_t *c, int threadID, int amt) {
    int cpu = threadID % NUMCPUS;
    //printf("the threadID %d in %d CPU\n", threadID, cpu);
    pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt;
    if (c->local[cpu] >= c->threshold) {
    // transfer to global (assumes amt>0)
    pthread_mutex_lock(&c->glock);
    c->global += c->local[cpu];
    pthread_mutex_unlock(&c->glock);
    c->local[cpu] = 0;
 }
    pthread_mutex_unlock(&c->llock[cpu]);
 }

 // get: just return global amount (approximate)
 int get(counter_t *c) {
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val; // only approximate!
 }

 void *thread_function(void *args){
    myargs *arg = (myargs*)args;
    pthread_t threads = pthread_self();
    //printf("the id is %d\n", arg->threadid);
    //printf("the id %d is %d\n", arg->threadid, threads);
    for(int i=0; i<1e6/arg->threads; i++){
        update(arg->ct, (int)threads, arg->amt);
    }
    return NULL;
 }

 int main(int argc, char* argv[]){
    counter_t *gc = (counter_t*)malloc(sizeof(counter_t));
    counter_t *lc[NUMCPUS];
    pthread_t threads[NUMCPUS][3];
    double start;
    for(int i=0; i<NUMCPUS; i++){
        lc[i] = (counter_t *)malloc(sizeof(counter_t));
        int s = 2;
        init(lc[i], s);
    start = GetTime();
    for(int j=0; j<THREADSEACHCPU; j++){
        myargs *args = (myargs*)malloc(sizeof(myargs));
        args->ct = lc[i];
        args->threads = NUMCPUS*THREADSEACHCPU;
        args->amt = 1;
        args->thre = s;
        args->threadid = i*THREADSEACHCPU + j;
        //printf("the number is %d\n",i*THREADSEACHCPU + j);
        pthread_create(&threads[i][j], NULL, thread_function, args);
    }
    }
    for(int i=0; i<NUMCPUS; i++){
        for(int k=0; k<THREADSEACHCPU; k++){
        pthread_join(threads[i][k], NULL);
    }
    }
    double end = GetTime();
    printf("time is %f\n", end-start);

 }


 