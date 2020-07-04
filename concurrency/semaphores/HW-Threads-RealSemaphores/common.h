#ifndef __common_h__
#define __common_h__

#include<sys/time.h>
#include<sys/stat.h>
#include<assert.h>
#include<pthread.h>
double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert( rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec/1e6;
}

void Spin(int howlong){
    double t = GetTime();
    while((GetTime() - t) < (double) howlong)
        ;
}

typedef struct __sem_t {
    int value;
    pthread_cond_t cond;
    pthread_mutex_t lock;
} sem_t;

void Sem_init (sem_t *s, int value){
    s->value = value;
    pthread_cond_init(&s->cond, NULL);
    pthread_mutex_init(&s->lock, NULL);
}

void Sem_wait(sem_t *s){
    pthread_mutex_lock(&s->lock);
    while(s->value <= 0){
        pthread_cond_wait(&s->cond,&s->lock);
    }
    s->value--;
    pthread_mutex_unlock(&s->lock);
}

void Sem_post(sem_t *s){
    pthread_mutex_lock(&s->lock);
    s->value++;
    pthread_cond_signal(&s->cond);
    pthread_mutex_unlock(&s->lock);
}
#endif