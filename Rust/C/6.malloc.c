#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{  // malloc() memory allocation
    // malloc() is a function that allocates memory at run time and
    // returns a pointer of type void which can be casted into pointer of any form.
    // syntax: ptr = (cast-type*) malloc(byte-size)
    // initialises each block with some garbage value
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
    free(ptr);

    return 0;
}