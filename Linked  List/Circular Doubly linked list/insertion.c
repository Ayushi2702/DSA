#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;

void create(int A[], int n) {
    int i;
    struct node *last, *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = first->next = first;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = first;
        t->prev = last;
        last->next = t;
        last = t;
    }
    
    // Linking the last node to the first node
    first->prev = last;
    last->next=first;
}

int insert(struct node *p,int index,int key)
{
    struct node *t;
    if(index<1)
    {
        return -1;
    }
    if(index==1)
    {
     t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->next=first;
        t->prev=first->prev;
        first->prev=t;
        t->prev->next=t;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }

        t=(struct node *)malloc(sizeof(struct node ));
        t->data=key;
        t->prev=p;
        t->next=p->next;
        p->next=t;
        t->next->prev=t;



    }
}




void display(struct node *p) {
    struct node *start = p;
    do {
        printf("%d\n", p->data);
        p = p->next;
    } while (p != start);
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(first);
    printf("After insertion of element : \n");
    insert(first,2,8);
    display(first);

    
    return 0;
}
