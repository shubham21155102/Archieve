#include <stdio.h>
#include <string.h>
int main(){
    // static memory allocation
    // memory is allocated at compile time
    //example:
    int a[5];
    int a[5] = {1, 2, 3, 4, 5};
    // dynamic memory allocation
    // memory is allocated at run time
    // example:
    int *ptr;
    ptr = (int *)malloc(5 * sizeof(int));
    free(ptr);

    return 0;
}