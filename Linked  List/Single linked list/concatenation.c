#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create(int A[], int n) {
    struct Node *first = NULL;
    struct Node *last = NULL;
    struct Node *t;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node *concat(struct Node *p, struct Node *q) {
    struct Node *third;
    third = p;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
    return third;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {6, 7, 8, 9, 10};
    struct Node *first = create(A, 5);
    struct Node *second = create(B, 5);

    printf("First list: ");
    display(first);

    printf("Second list: ");
    display(second);

    struct Node *third = concat(first, second);

    printf("Concatenated list: ");
    display(third);

    return 0;
}
