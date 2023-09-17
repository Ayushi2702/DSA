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

int issort(struct Node *p)
{
  int x=-5446;
  while(p!=NULL)
  {
    if(p->data<x)
    {
      return -1;
    }
    else{
      x=p->data;
      p=p->next;}
  
  }
  return 1;
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
    int A[]={1,2,30,4,5};
    create(A,5);
    display(first);
    printf("%d",issort(first));
    if(issort(first)==1)
    {
        printf("\nSorted");
    }
    else if(issort(first)==-1)
    {
        printf("\nNot sorted!");
    }
    return 0;
}