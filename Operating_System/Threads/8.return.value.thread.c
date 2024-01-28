#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
// cause error because of returning address of local variable
// so we have to use malloc / dynamic memory allocation
// void* dice_result(){
//     int res=(rand()%6+1);
//     printf("Dice value: %d\n",res);
//     return ((void *)&res);
//     return NULL;
// }
// int main(int argc,char* argv[]){
//     int *res;
//     pthread_t th;
//     srand(time(NULL));
//     if(pthread_create(&th,NULL,dice_result,NULL)!=0)return 1;
//     if(pthread_join(th,NULL)!=0)return 2;
//     printf("Dice value: %d\n",*res);

//     return 0;
// }
void *dice_result()
{
    int res = (rand() % 6 + 1);
    int *value = malloc(sizeof(int));
    *value = res;
    return ((void *)value);
    return NULL;
}
int main(int argc, char *argv[])
{
    int *resi;
    srand(time(NULL));
    pthread_t th;

    if (pthread_create(&th, NULL, dice_result, NULL) != 0)
        return 1;
    if (pthread_join(th, (void **)&resi) != 0)
        return 2;
    printf("Dice address: %p\n", resi); // %p is used for printing address:Dice value: 0xb331000181de4470
    printf("Dice value: %d\n", *resi);
    free(resi);
    return 0;
}
// Dice address: 0x143704080
// Dice value: 2