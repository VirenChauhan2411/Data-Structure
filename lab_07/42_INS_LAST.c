#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node{
    int info;
    struct node*  link;
};
struct node*first = NULL;

void insertAtEnd(int x)
{
    struct node* Newnode;
    Newnode = (struct node*)malloc(sizeof(struct node));

    Newnode->info = x;
    Newnode->link = NULL;

    struct node*save;

    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = Newnode;

}