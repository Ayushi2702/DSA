#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};  //created inside a stack


    //second method
   int *B[3];   //3 is for rows 
                //pointer is created inside stack

     //int **C; //third pointer
     for(int i=0;i<3;i++)
     {
        for(int j=0;j<4;j++)
        {
            printf("%d",A[i][j]);
        }
        printf("\n");
     }

   B[0]=(int *)malloc(4*sizeof(int));
   B[1]=(int *)malloc(4*sizeof(int));//stored in heap
   B[2]=(int *)malloc(4*sizeof(int));
  for(int i=0;i<3;i++)
     {2
        for(int j=0;j<4;j++)
        {
            printf("%d",B[i][j]);
        }
        printf("\n");
     }

//   C=(int ** )malloc(3*sizeof(int *));
//   C[0]=(int *)malloc(4*sizeof(int ));
//   C[1]=(int *)malloc(4*sizeof(int ));
//   C[2]=(int *)malloc(4*sizeof(int ));
}