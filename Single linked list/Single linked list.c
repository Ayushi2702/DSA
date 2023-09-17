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

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d",p->data);
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