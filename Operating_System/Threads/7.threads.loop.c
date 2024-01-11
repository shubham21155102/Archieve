#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_mutex_t lock;
int mails = 0;
void *resume(void *args)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&lock);
        mails++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main()
{

    pthread_mutex_init(&lock, NULL);
    pthread_t p[8];
    // sequential execution // not the correct way to execute threads in loop
    // for (int i = 0; i < 8; i++)
    // {
    //     pthread_create(&p[i], NULL, resume, NULL);
    //     printf("Thread %d created\n", i);
    //     pthread_join(p[i], NULL);
    //     printf("Thread %d finished\n", i);
    // }
    // Thread 0 created
    // Thread 0 finished
    // Thread 1 created
    // Thread 1 finished
    // Thread 2 created
    // Thread 2 finished
    // Thread 3 created
    // Thread 3 finished
    // Thread 4 created
    // Thread 4 finished
    // Thread 5 created
    // Thread 5 finished
    // Thread 6 created
    // Thread 6 finished
    // Thread 7 created
    // Thread 7 finished
    // Number of mails: 8000000
    // parallel execution
    for(int i=0;i<8;i++){
        pthread_create(&p[i],NULL,resume,NULL);
        printf("Thread %d created\n",i+1);
    }
    for(int i=0;i<8;i++){
        pthread_join(p[i],NULL);
        printf("Thread %d finished\n",i+1);
    }
    //     Thread 1 created
    // Thread 2 created
    // Thread 3 created
    // Thread 4 created
    // Thread 5 created
    // Thread 6 created
    // Thread 7 created
    // Thread 8 created
    // Thread 1 finished
    // Thread 2 finished
    // Thread 3 finished
    // Thread 4 finished
    // Thread 5 finished
    // Thread 6 finished
    // Thread 7 finished
    // Thread 8 finished
    // Number of mails: 8000000
    // this is only the output that we want to show
    // how threads are executed in parallel
    // but they execute in random order
    // so we can't predict the output

    printf("Number of mails: %d\n", mails);
    return 0;
}