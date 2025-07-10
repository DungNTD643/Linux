#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data_ready;
int end_produce;
int data;


void *producer(void *arg){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&lock);
        data = rand();
        data_ready = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
        usleep(10);
    }
    return NULL;
}

void *consumer(void *arg){
    for (int i = 0; i < 10; i++){
            pthread_mutex_lock(&lock);
            while(data_ready == 0){
                pthread_cond_wait(&cond, &lock);
            }
            data_ready = 0;
            printf("data = %d\n",data);
            pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void main(int argc, char *argv[]){
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, producer, NULL);
    pthread_create(&thread2, NULL, consumer, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}