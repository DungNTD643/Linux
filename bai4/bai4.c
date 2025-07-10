#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
int end_of_prg = 0;
int data = 0;

void *read_process(void *arg) {
    int ID = *(int *)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);
        if (end_of_prg) {
            pthread_rwlock_unlock(&rwlock);
            break;
        }
        printf("Start to READ with ID: %d \n", ID);
        printf("Data = %d\n", data);
        printf("READ finished with ID: %d\n", ID);
        pthread_rwlock_unlock(&rwlock);
        usleep(5000);
    }
    return NULL;
}

void *write_process(void *arg) {
    int ID = *(int *)arg;
    for (int i = 0; i < 100; i++) {
        pthread_rwlock_wrlock(&rwlock);
        printf("Start to WRITE with ID: %d\n", ID);
        data++;
        printf("WRITE finished with ID: %d\n", ID);
        pthread_rwlock_unlock(&rwlock);
        usleep(1000);
    }

    pthread_rwlock_wrlock(&rwlock);
    end_of_prg = 1;
    pthread_rwlock_unlock(&rwlock);
    return NULL;
}

int main() {
    pthread_t read[5];
    pthread_t write[2];
    int read_ids[5], write_ids[2];

    for (int i = 0; i < 2; i++) {
        write_ids[i] = i + 1;
        pthread_create(&write[i], NULL, write_process, &write_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        read_ids[i] = i + 1;
        pthread_create(&read[i], NULL, read_process, &read_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(write[i], NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(read[i], NULL);
    }

    printf("Final data value = %d\n", data);
    return 0;
}
