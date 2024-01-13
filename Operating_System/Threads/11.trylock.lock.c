#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
pthread_mutex_t mutex;
//uses of trylock is to check if the lock is available or not
//if the lock is available then it will lock the mutex and return 0
//if the lock is not available then it will return EBUSY
void *routine(void *arg)
{
    if (pthread_mutex_lock(&mutex) == 0)
    {
        printf("Got Lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Failed to get lock\n");
    }
    return NULL;
}
void *routine_lock(void *arg)
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got Lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("Failed to get lock\n");
    }
    return NULL;
}
int main()
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 2;
        }
    }
    return 0;
}
