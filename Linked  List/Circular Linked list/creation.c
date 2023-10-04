#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct node *last,*t;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=first;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

int count(struct node *p)
{
    int c=0;
    do{
        c++;
        p=p->next;
    }while(p!=first);
    return c;
}

void display(struct node *p)
{
    do{
        printf("%d\t",p->data);
        p=p->next;

    }while(p!=first);
}



int main()
{ int A[]={1,2,3,4,5};
create(A,5);
display(first);
printf("\nThe number of nodes in this circular linked list is %d",count(first));
return 0;


}