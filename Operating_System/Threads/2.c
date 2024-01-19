#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
void *check(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Hello World from Thread\n");
    sleep(1);
    printf("Checking Parallel Execution from Thread\n");
    return NULL;
}

int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,check,NULL);
    pthread_create(&t2,NULL,check,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
   
   
}
