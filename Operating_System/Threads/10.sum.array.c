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
// output:
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Creation started
// Prime number 1: 2
// Prime number 2: 5
// Prime number 3: 10
// Prime number 4: 17
// Prime number 5: 28
// Prime number 6: 41
// Prime number 7: 58
// Prime number 8: 77
// Prime number 9: 100
// Prime number 10: 129

