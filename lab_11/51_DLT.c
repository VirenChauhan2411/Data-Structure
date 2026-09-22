#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *new = NULL;
struct node *last = NULL;

void InsertAtEnd(int insval)
{
    new = (struct node*)malloc(sizeof(struct node));
    new->info = insval;
    if(first == NULL)
    {
        first = new;
        new->link = first;
        last = new;
    }
    else
    {
        last->link = new;
        new->link = first;
        last = new;
    }
}

void deleteNode(int val)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (first == last && first->info == val)
    {
        free(first);
        first = NULL;
        last = NULL;
        return;
    }

    if (first->info == val)
    {
        struct node *temp = first;
        first = first->link;
        last->link = first;
        free(temp);
        return;
    }

    struct node *save = first;
    while (save->link != first && save->link->info != val)
    {
        save = save->link;
    }

    if (save->link->info == val)
    {
        struct node *temp = save->link;
        save->link = temp->link;
        if (temp == last)
        {
            last = save;
        }
        free(temp);
    }
    else
    {
        printf("Node with value %d not found\n", val);
    }
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *save = first;
    do
    {
        printf("%d ", save->info);
        save = save->link;
    }
    while(save != first);
    printf("\n");
}

int main()
{
    int n, insval, dlt;
    printf("enter the size of Node : ");
    scanf("%d", &n);

    printf("Enter the Value : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &insval);
        InsertAtEnd(insval);
    }

    printf("Enter the Value for delate Node : ");
    scanf("%d", &dlt);

    deleteNode(dlt);

    printf("Circular Linked List after deletion: ");
    display();
    return 0;
}