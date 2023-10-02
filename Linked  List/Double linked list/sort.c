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
        last->next=t;
        t->prev=last;
        last=t;
        
        
    }
}
void sortinsert(struct node *p, int key) {
    struct node *t, *q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->next = t->prev = NULL;

    // If the list is empty, make the new node the first node
    if (!p) {
        first = t;
        return;
    }

    // Traverse the list to find the correct position for insertion
    while (p && p->data < key) {
        q = p;
        p = p->next;
    }

    // Insert the new node in the sorted position
    if (!q) {
        // Insert at the beginning of the list
        t->next = p;
        p->prev = t;
        first = t; // Update the first pointer to the new node
    } else {
        // Insert in the middle or at the end of the list
        t->next = p;
        t->prev = q;
        if (p) {
            p->prev = t;
        }
        q->next = t;
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
    int A[]={1,2,3,5};
    create(A,5);
    // display(first);
    sortinsert(first,6);
    display(first);
    return 0;
}