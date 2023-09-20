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
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
int length(struct node *p)
{
    int l=0;
    while(p!=0)
    {
       l++;
       p=p->next;
    }
    return l;
}

void insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index<0||index>length(p))
    {
        return ;
    }

    if(index==0)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;

    }

    else{
      for(i=0;i<index-1;i++)
      {
        p=p->next;
      }
      t=(struct node *)malloc(sizeof(struct node));
      t->data=x;
      t->prev=p;
      t->next=p->next;
      if(p->next)
      {
        p->next->prev=t;
      }
        p->next=t;
            


    }
}

void display(struct node *p)
{
    while(p!=0)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

//contriubtion again from ayushi
int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    insert(first,3,20);
    printf("\nAfter insertion of a node :\t");
    display(first);
    return 0;
}