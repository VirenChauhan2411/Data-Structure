#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
void read(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    first = new;
}

void insertFirst(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    first = new;
}

void display()
{
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d \n", save->info);
        save = save->link;
    }
}

void deleatFirst()
{
    struct node *temp = first;
    first = first->link;
    free(temp);
}

void insertEnd(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = NULL;
    struct node *save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = new;
}

void deleatLast()
{
    struct node *save = first;
    while ((save->link)->link != NULL)
    {
        save = save->link;
    }
    struct node *temp = save;
    save->link = NULL;
    free(temp);
}

void count()
{
    struct node *save = first;
    int c = 0;
    while (save != NULL)
    {
        c++;
        save = save->link;
    }
    printf("count=%d", c);
}
void main()
{
    int n, x,i=0,j;
    printf("Enter number of node:");
    scanf("%d",&j);
    printf("Enter value:");
    for(int k=1;k<=j;k++){
        scanf("%d",&x);
        read(x);
    }

    while(i==0){
        printf("for break loop enter 1 else 0:");
        scanf("%d",&i);
    printf("Enter n=1,2,3,4,5,6 for insertfirst,display,deleatfirst,insertEnd,deleatlast,count:");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("Enter value:");
        scanf("%d", &x);
        insertFirst(x);
        break;
    case 2:
        display();
        break;
    case 3:
        deleatFirst();
        break;
    case 4:
        printf("Enter value:");
        scanf("%d", &x);
        insertEnd(x);
        break;
    case 5:
        deleatLast();
        break;
    case 6:
        count();
        break;

    default:
        break;
    }
}
}