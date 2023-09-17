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

void removedup(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;

        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
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
    int A[]={1,2,4,4,5};
    create(A,5);
    display(first);
    printf("\nAfter removal of duplicate element: ");
    removedup(first);
    display(first);
    return 0;
}