#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "common_threads.h"
#include "common.h"
//
// Here, you have to write (almost) ALL the code. Oh no!
// How can you show that a thread does not starve
// when attempting to acquire this mutex you build?
//

typedef struct __ns_mutex_t {
    int room1, room2;
    sem_t lock, door1, door2;
} ns_mutex_t;

void ns_mutex_init(ns_mutex_t *m) {
    Sem_init(&m->lock, 1);
    Sem_init(&m->door1, 1);
    Sem_init(&m->door2, 0);
    m->room1 = m->room2 = 0;
}

void ns_mutex_acquire(ns_mutex_t *m) {
    Sem_wait(&m->lock);
    m->room1 ++ ;
    Sem_post(&m->lock);
    Sem_wait(&m->door1);
    m->room2++;
    Sem_wait(&m->lock);
    m->room1--;
    if(m->room1 == 0){
        Sem_post(&m->lock);
        Sem_post(&m->door2);
    }else{
        Sem_post(&m->lock);
        Sem_post(&m->door1);
    }
    Sem_wait(&m->door2);
    m->room2--;
}

void ns_mutex_release(ns_mutex_t *m) {
    if(m->room2==0){
        Sem_post(&m->door1);
    }else{
        Sem_post(&m->door2);
    }
}
ns_mutex_t m;
int counter = 0;

void *worker(void *arg) {
    ns_mutex_acquire(&m);
    counter++;
    ns_mutex_release(&m);
    return NULL;
}

int main(int argc, char *argv[]) {
    assert(argc == 2);
    int num_threads = atoi(argv[1]);
    ns_mutex_init(&m);
    pthread_t p[num_threads];
    printf("parent: begin\n");

    int i;
    for (i = 0; i < num_threads; i++)
	    Pthread_create(&p[i], NULL, worker, NULL);

    for (i = 0; i < num_threads; i++)
	    Pthread_join(p[i], NULL);

    printf("counter: %d\n", counter);
    printf("parent: end\n");
}
