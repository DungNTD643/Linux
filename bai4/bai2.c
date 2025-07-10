#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

int count;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void *print_message(void *arg){
    int *id = (int *)arg;
    int index;
    for(index = 0; index < 1000000; index++){
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    printf("%d\n", count);
}

void main(int argc, char *argv[]){
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, print_message, NULL);
    pthread_create(&thread2, NULL, print_message, NULL);
    pthread_create(&thread3, NULL, print_message, NULL);
   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}