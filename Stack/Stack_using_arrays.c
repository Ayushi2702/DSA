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

void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack overflow\n");

    }

   else{
       st->top++; 
       st->S[st->top]=x;

   } 
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack underflow\n");
    }

    else{
        x=st->S[st->top--];
    }
    return x;
}

 int peek(int index,struct Stack st)
{
    int x=-1;
    if(st.top-index+1<0)
    {
        printf("Invalid index");
    }
    x=st.S[st.top-index+1];
    return x;
}



int isEmpty(struct Stack st)
{
    if(st.top==-1)
      return 1;
   else
     return 0; 
}


int isFull(struct Stack st)
{
    return st.top==st.size-1;
}

void display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
}f

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,50);
    printf("%d \n",peek(5,st));

    display(st);

}