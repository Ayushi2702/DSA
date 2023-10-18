// In most programming languages, the size of an array is fixed once it is created. 
// This means that you cannot directly increase or decrease the size of an array after it has been initialized. 
// The reason behind this limitation is related to how arrays are stored in computer memory.
// When you create an array, the programming language allocates a contiguous block of memory to store the elements of the array.
//  Each element in the array occupies a specific amount of memory, and they are stored one after another in this block of memory.
//   The size of this block of memory is determined by the number of elements in the array multiplied by the size of each element.
// If you were allowed to dynamically change the size of an array (by increasing or decreasing it), it would require moving the entire array to a new location in the computer's memory.
// This operation can be very time-consuming, especially for large arrays, because it would involve allocating a new block of memory, copying the existing elements to the new location, and then deallocating the old block of memory. This process is not efficient and can lead to performance issues, especially in time-sensitive applications

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;
    p=(int *)malloc(5*sizeof(int ));
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    q=(int *)malloc(7*sizeof(int));
    for(int i=0;i<5;i++)
    {
        q[i]=p[i];
    }
    free(p);
    p=q;
    q=NULL;
    for(int i=0;i<5;i++)
    {
        printf("%d\t",p[i]);

    }
    return 0;


}