#include <stdio.h>
#include<stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
  int i;
  struct Node *last,*t;
  first=(struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
  first->next=NULL;
  last=first;
  for(i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;

  }


}
void insertatbeg(struct Node *p,int key)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->next=first;
    first=t;
    

}
void insertatpos(int pos,int key,struct Node *p)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;

}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    display(first);
    printf("\nAfter insertion at the beginning :");
     insertatbeg(first,17);
    printf("\nInsertion at the fourth position:");
     insertatpos(3,20,first);
     display(first);

     return 0;
}