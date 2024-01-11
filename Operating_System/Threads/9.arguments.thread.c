#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void *getPrime(void *arg)
{
    sleep(1);
    int i = *((int *)arg);
    int *result = malloc(sizeof(int));
    *result = primes[i];
    pthread_exit(result);
}
int main()
{
    pthread_t p[10];
    for (int i = 0; i < 10; i++)
    {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&p[i], NULL, getPrime, arg);
        printf("Creation started\n");
    }

    for (int i = 0; i < 10; i++)
    {
        int *res;
        pthread_join(p[i], (void **)&res);
        printf("Prime number %d: %d\n", i + 1, *res);
        free(res);
    }
    return 0;
}
