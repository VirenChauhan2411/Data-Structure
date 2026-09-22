#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *copy = NULL;

void InsertAtEnd(int x)
{
    struct node *newnode,*save;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
        return;
    }

    save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;
}

void copylist()
{
    struct node *temp, *newnode, *last;

    if (first == NULL)
    {
        printf("empty");
        return;
    }

    temp = first;

    while (temp != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->info = temp->info;
        newnode->link = NULL;

        if (copy == NULL)
        {
            copy = newnode;
            last = newnode;
        }
        else
        {
            last->link = newnode;
            last = newnode;
        }
        temp = temp->link;
    }
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ->", head->info);
        head = head->link;
    }
}

int main()
{
    int i, n, x;

    printf("enter numbers o fnodes : ");
    scanf("%d", &n);


     printf("enter data : ");

    for (i = 1; i <= n; i++)
    {
       
        scanf("%d", &x);

        InsertAtEnd(x);
    } 
    copylist();

    printf("\nOriginal Linked List:");
    display(first);

    printf("\nCopied Linked List:");
    display(copy);

    return 0;
}