#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
sem_t *s1;
void *child1(void *args){
    // printf(" before value:%d\n",sem_getvalue(s1, NULL));
        printf("1\n");

    sem_wait(s1);
    printf("1\n");
    // printf("value:%d\n",sem_getvalue(s1, NULL));
    return NULL;
}

void *child2(void *args){
    sleep(1);
    printf("2\n");
    sem_post(s1);
    // sem_wait(s1);
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t p1, p2;
    if ((s1 = sem_open("/semaphore", O_CREAT, 0644, 1)) == SEM_FAILED) {
    perror("sem_open");
    exit(2);
  }   
//    printf("value:%d\n",sem_getvalue(s1, NULL));

    // sem_init(&s1, 0, -10);
    pthread_create(&p1, NULL, child1, NULL);
    pthread_create(&p2, NULL, child2, NULL);
    sem_wait(s1);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    sem_unlink("/test");
    printf("end\n");
}