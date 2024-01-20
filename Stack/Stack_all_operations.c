#include <stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};


void create(struct Stack *st)
{
    printf("Enter Size ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));

}

void display(struct Stack st)
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
}