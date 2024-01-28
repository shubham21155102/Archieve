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