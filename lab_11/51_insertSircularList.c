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


void InsertAtFirst(int insval)
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
        new->link = first;
        last->link = new;
        first = new;
    }
}
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
void display()
{
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
    int n, insval;
    printf("enter the size of Node : ");
    scanf("%d", &n);

    printf("Enter the Value : ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &insval);
        InsertAtFirst(insval);
    }
    printf("Enter the Value for Insert Node : ");
    scanf("%d", &insval);
    InsertAtFirst(insval);
    InsertAtEnd(insval);
    display();
    return 0;
}