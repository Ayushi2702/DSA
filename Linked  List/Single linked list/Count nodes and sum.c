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
int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
       
    }
    return c;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s=s+(p->data);
        p=p->next;
    }
    return s;
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
    printf("\nThe number of nodes in this list is : ");
    printf("%d",count(first));
    printf("\nThe sum of nodes in this list is : ");
    printf("%d",sum(first));
    return 0;
}