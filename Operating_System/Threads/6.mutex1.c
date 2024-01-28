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