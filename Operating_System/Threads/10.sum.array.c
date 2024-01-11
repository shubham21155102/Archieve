#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

typedef struct {
    int *arr;
    int size;
} ThreadArgs;

int sumOfArray(ThreadArgs *args) {
    int sum = 0;
    for (int i = 0; i < args->size; i++) {
        sum += args->arr[i];
    }
    return sum;
}

int main() {
    pthread_t p[10];
    int result[10]; // Array to store results
    ThreadArgs args[10]; // Array to store thread arguments

    for (int i = 0; i < 10; i++) {
        args[i].arr = primes;
        args[i].size = i + 1;

        pthread_create(&p[i], NULL, (void *(*)(void *))sumOfArray, &args[i]);
        printf("Creation started\n");
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(p[i], (void **)&result[i]);
        printf("Prime number %d: %d\n", i + 1, result[i]);
    }

    return 0;
}
