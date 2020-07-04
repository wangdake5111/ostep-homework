#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "common_threads.h"

// If done correctly, each child should print their "before" message
// before either prints their "after" message. Test by adding sleep(1)
// calls in various locations.

// You likely need two semaphores to do this correctly, and some
// other integers to track things.

typedef struct __barrier_t {
    // add semaphores and other information here
    sem_t allArrive, counter;
    int value;
    int count;
} barrier_t;


// the single barrier we are using for this program
barrier_t b;
pthread_mutex_t lock;
void barrier_init(barrier_t *b, int num_threads) {
    // initialization code goes here
    b->value = num_threads;
    b->count = 0;
    Sem_init(&b->allArrive, 0);
    Sem_init(&b->counter, 1);

}

void barrier(barrier_t *b) {
    // barrier code goes here
    Sem_wait(&b->counter);
    b->count++;
    printf("%d\n",b->count);
    // usleep(100);
    if(b->count == b->value){
        Sem_post(&b->allArrive);
    }
    Sem_post(&b->counter);
    // Sem_post(&b->allArrive);
    Sem_wait(&b->allArrive);
    Sem_post(&b->allArrive);
}

//
// XXX: don't change below here (just run it!)
//
typedef struct __tinfo_t {
    int thread_id;
} tinfo_t;

void *child(void *arg) {
    tinfo_t *t = (tinfo_t *) arg;
    printf("child %d: before\n", t->thread_id);
    barrier(&b);
    //sleep(1);
    printf("child %d: after\n", t->thread_id);
    return NULL;
}


// run with a single argument indicating the number of 
// threads you wish to create (1 or more)
int main(int argc, char *argv[]) {
    assert(argc == 2);
    int num_threads = atoi(argv[1]);
    assert(num_threads > 0);

    pthread_t p[num_threads];
    tinfo_t t[num_threads];

    printf("parent: begin\n");
    barrier_init(&b, num_threads);
    pthread_mutex_init(&lock, NULL);
    int i;
    for (i = 0; i < num_threads; i++) {
	t[i].thread_id = i;
	Pthread_create(&p[i], NULL, child, &t[i]);
    }

    for (i = 0; i < num_threads; i++) 
	Pthread_join(p[i], NULL);

    printf("parent: end\n");
    return 0;
}

