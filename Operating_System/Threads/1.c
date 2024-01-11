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
