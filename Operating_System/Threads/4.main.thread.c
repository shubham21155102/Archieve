#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
int x=8;
void *routine(void *arg)
{
    x++;
    sleep(1);
    printf("x=%d\n",x);
}
void *check(void *arg)
{
    pthread_t tid = pthread_self();
    printf("Hello World from Thread\n");
    printf("value of x=%d\n",x);
    sleep(1);
    printf("Checking Parallel Execution from Thread\n");
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, check, NULL);
    pthread_create(&t2, NULL, check, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}

// Hello World from Thread
// Hello World from Thread
// value of x=8
// value of x=8
// Checking Parallel Execution from Thread
// Checking Parallel Execution from Thread

// one observation is that the value of x is not changed in the thread. 
// This is because the threads are created and executed in parallel and 
// the CPU is assigned to the threads by the OS. So, the threads are not aware of the changes 
// made in the other threads.
// also all the memory is shared between the threads.
// so the value of x is not changed in the thread.