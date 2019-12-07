#include <stdio.h>
#include "insertionsort.h"

void insertionsort(int a[], int left, int right)
{
    int i;
    struct node *head;
    struct node *p;

    head = malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Error: malloc failed in insertionsort.c\n");
        exit(1);
    }
    head->value = a[left];
    head->next = NULL;

    for (i = left + 1; i <= right; i++)
    {
        head = add_to_list(head, a[i]);
    }
    for (i = left; i <= right; i++)
    {
	counter++;
        a[i] = head->value;
        p = head;
        head = head->next;
        free(p);
    }

    return;
}

struct node *add_to_list(struct node *head, int n)
{
    struct node *new_node;
    struct node *p, *q;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in insertionsort.c\n");
        exit(1);
    }
    new_node->value = n;

    if (head->value > new_node->value)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }

    p = head;
    q = p->next;
    while (q != NULL && q->value <= n)
    {
	counter++;
        p = q;
        q = p->next;
    }

    if (q != NULL)
    {
        new_node->next = q;
        p->next = new_node;
    }
    else
    {
        new_node->next = NULL;
        p->next = new_node;
    }

    return head;
}
