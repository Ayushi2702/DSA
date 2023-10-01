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
    return 0;
}
