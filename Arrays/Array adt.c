#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

int main(){
    struct Array arr;
    int n,i;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
  arr.A=(int *)malloc(arr.sizeof(int));
  arr.length=0;
printf("Enter the number of elements ");
scanf("%d",&n);


 printf("Enter all the elements \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr.A[i]);
  }
    arr.length=n;

    



}
