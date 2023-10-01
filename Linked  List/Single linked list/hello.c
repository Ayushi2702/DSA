#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct node *last,*t;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));//g
        t->data=A[i]; //hii
        t->next=last->next;
        last->next=t;
        t->prev=last;
        last=t;
        
        
    }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}


int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    return 0;
}