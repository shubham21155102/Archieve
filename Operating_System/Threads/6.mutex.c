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