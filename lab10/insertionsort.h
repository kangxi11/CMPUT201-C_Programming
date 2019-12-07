#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void insertionsort(int a[], int left, int right);

struct node *add_to_list(struct node *head, int n);
extern int counter;
