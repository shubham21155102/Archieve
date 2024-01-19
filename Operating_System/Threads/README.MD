# Threads

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
void *check(void *arg)
{
    int cpu = sched_getcpu();
    printf("Hello World from CPU %d\n", cpu);
    sleep(1);
    printf("Checking Parallel Execution from CPU %d\n", cpu);
    return NULL;
}
int main()
{
    // parallel execution
    pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    pthread_create(&t1, NULL, check, NULL);
    pthread_create(&t2, NULL, check, NULL);
    pthread_create(&t3, NULL, check, NULL);
    pthread_create(&t4, NULL, check, NULL);
    pthread_create(&t5, NULL, check, NULL);
    pthread_create(&t6, NULL, check, NULL);
    pthread_create(&t7, NULL, check, NULL);
    pthread_create(&t8, NULL, check, NULL);
    pthread_create(&t9, NULL, check, NULL);
    pthread_create(&t10, NULL, check, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);
    pthread_join(t9, NULL);
    pthread_join(t10, NULL);
    // Hello World from CPU 3
    // Hello World from CPU 15
    // Hello World from CPU 15
    // Hello World from CPU 15
    // Hello World from CPU 15
    // Hello World from CPU 11
    // Hello World from CPU 15
    // Hello World from CPU 15
    // Hello World from CPU 0
    // Hello World from CPU 7
    // Checking Parallel Execution from CPU 3
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 11
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 15
    // Checking Parallel Execution from CPU 0
    // Checking Parallel Execution from CPU 7
    // This is because the threads are created and executed in parallel and the CPU is assigned to the threads by the OS.

    // It seems the output  provided shows the "Hello World" messages and
    // "Checking Parallel Execution" messages, each accompanied by a CPU number.
    // This output might indicate that the code was executed on multiple CPUs,
    // which is a common behavior in modern systems that support multiprocessing.

    // The CPU numbers displayed in your output suggest that the threads are being executed
    // on different cores (CPUs) of your system. Each line with "Hello World" and "Checking Parallel Execution"
    // is associated with a specific CPU number. This occurrence indicates that the threads
    // were indeed executed in parallel across multiple CPUs.

    // This behavior is expected when running a multithreaded program on a system with multiple CPU cores.
    // The operating system scheduler distributes the threads across available CPU cores for parallel execution,
    //  which explains why you're seeing different CPU numbers associated with the output.
    return 0;
}

```

# Parallel Execution

```c
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

```

# Process vs Thread

```c
#include <stdlib.h>    // for exit()
#include <stdio.h>     // for printf()
#include <unistd.h>    // for sleep()
#include <sys/wait.h>  // for wait()
#include <sys/types.h> // for pid_t
int main()
{
    pid_t pid;
    int x = 60;
    pid = fork();
    printf("pid=%u\n", (unsigned int)pid);
    printf("pid = %d \n", getpid());

    if (pid < 0)
    {
        printf("Fork Failed\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        x += 90;
        printf("Hello World from Child Process\n");
        sleep(1);
        printf("Checking Parallel Execution from Child Process\n");
    }
    else
    {
        wait(NULL);
        printf("Hello World from Parent Process\n");
        sleep(1);
        printf("Checking Parallel Execution from Parent Process\n");
    }
    printf("value of x=%d\n", x);
    // pid=17269
    // pid = 17268
    // pid=0
    // pid = 17269
    // Hello World from Child Process
    // Checking Parallel Execution from Child Process
    // value of x=150
    // Hello World from Parent Process
    // Checking Parallel Execution from Parent Process
    // value of x=60
}
```

```c
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
```
# Race Condition

```c
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void *routine()
{
    //  mails++; //Number of mails: 2
    for (int i = 0; i < 1000000; i++)
    {
        mails++;
        // read mails
        // increment
        // write mails
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2, p3, p4;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
    if (pthread_join(p1, NULL) != 0)
    {
        return 3;
    }
    if (pthread_join(p2, NULL) != 0)
    {
        return 4;
    }
    printf("Number of mails: %d\n", mails);
    return 0;
}
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.ra
// ce.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1005181
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.race.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1005151
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.race.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1002782
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.race.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1018634
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.race.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1052655
// shubham@SHUBHAMs-MacBook-Air Threads % cd "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/" && gcc 5.race.condition.c -o 5.race.condition && "/Users/shubham/Downloads/shubham/system-design/Operating_System/Threads/"5.race.condition

// Number of mails: 1004893


// this is called Race condition each time we run the program we get different output

```
# Mutex
```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int mails=0;
int lock=0;
void *resume(void *arg){
    for(int i=0;i<1000000;i++){
        if(lock==1){
          
        }
        lock=1;
        mails++;
        lock=0;
    }
    return NULL;
}
int main(){
    pthread_t p1,p2;
    pthread_create(&p1,NULL,resume,NULL);
    pthread_create(&p2,NULL,resume,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("Number of mails: %d\n",mails);
    return 0;

}
```
```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int mails=0;
pthread_mutex_t lock;
void *resume(void *arg){
    for(int i=0;i<1000000;i++){
        pthread_mutex_lock(&lock);
        mails++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
int main(){
    pthread_t p1,p2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&p1,NULL,resume,NULL);
    pthread_create(&p2,NULL,resume,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("Number of mails: %d\n",mails);
    return 0;

}
// Output: always 2000000
// Explanation: The mutex lock ensures that only one thread can access the critical section at a time.
// The other thread has to wait for the first thread to release the lock.
// so here we are working with 2 threads and each thread is incrementing the value of mails 1000000 times.
```
# Thread Loop
```c
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
```
# Return Value from Thread
```c
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int value=(rand()%6)+1;
    int* result=malloc(sizeof(int));
    *result=value;
    return result;
}

int main(int argc, char* argv[]) {
    int* res;
    srand(time(NULL));
    pthread_t th;
    pthread_create(&th, NULL, roll_dice, NULL);
    pthread_join(th, (void**) &res);
    printf("Dice value: %d\n", *res);
    free(res);
    return 0;
}
```
# Arguments to Thread
```c
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

```
# Sum of Array
```c
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

```
# TryLock and Lock in c
