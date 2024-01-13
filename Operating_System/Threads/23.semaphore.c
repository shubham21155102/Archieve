#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void* args) {
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 4);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}
// Hello from thread 3
// Hello from thread 2
// Hello from thread 0
// Hello from thread 1
// no one has executed at the time of execution
// so no one has to wait
// so no one has to wait
// sem_init(&semaphore, 0, 4); 4 is the number of threads that can execute at a time
// sem_init(&semaphore, 0, 2); 2 is the number of threads that can execute at a time
// recursive mutex and semaphore are same but semaphore is more powerful
// semaphore can be used for inter process communication
// multiple threads can access the same semaphore
// semaphore is a counter
