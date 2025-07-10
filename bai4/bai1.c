#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

void *print_message(void *arg){
    int *id = (int *)arg;
    printf("ID cua thread: %d\n", *id);
}

void main(int argc, char *argv[]){
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, print_message, &thread1);
    pthread_create(&thread2, NULL, print_message, &thread2);
   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}