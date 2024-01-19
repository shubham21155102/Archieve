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
