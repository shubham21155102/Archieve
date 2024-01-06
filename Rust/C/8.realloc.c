#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    //realloc() re allocataion
    // realloc() function is used to dynamically change memory allocation of a previously allocated memory.
    // maintains the previous values and new blocks are initialised with garbage values
    // syntax: ptr = realloc(ptr, newSize);
    // large blocks of memory
    int n = 5;
    int *ptr;
    int arr[n];
    ptr =(int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(ptr + i) = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value of %d element is: %d\n", i + 1, ptr[i]);
    }
    // Reallocating ptr using realloc()
    ptr = realloc(ptr, 10 * sizeof(int));
    for (int i = 5; i < 10; i++)
    {
        *(ptr + i) = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("The value of %d element is: %d\n", i + 1, ptr[i]);
    }
    free(ptr);
    return 0;
}