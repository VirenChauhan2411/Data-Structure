#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;

};

struct node *l = NULL;
struct node *r = NULL;


void display()
{
    struct node *temp;
    temp = l;
    while(temp != NULL)
    {
        printf("%d ",temp->info);
        temp = temp->rptr;
    }
}
void insertAtFirst(int x)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(l == NULL)
    {
        r = l = newNode;
    }
    else 
    {
        newNode->rptr = l;
        l->lptr = newNode;
        l = newNode;
    }
    display();

}

void Delete(int position)
{
    struct node *temp = l;

    if(l == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(position == 1)
    {
        temp = l;
        if(l == r)
        {
            l = r = NULL;
        }
        else
        {
            l = l->rptr;
            l->lptr = NULL;
        }
        free(temp);
        return;
    }

    for(int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->rptr;
    }

    if(temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    if(temp == r)
    {
        r = r->lptr;
        r->rptr = NULL;
        free(temp);
        return;
    }

    temp->lptr->rptr = temp->rptr;
    temp->rptr->lptr = temp->lptr;
    free(temp);
    display();
}
void insertAtLast(int x)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    if(r == NULL)
    {
        l = r = newNode;
    }
    else
    {
        r->rptr = newNode;
        newNode->lptr = r;
        r = newNode;
    }
    display();
}
void main()
{
    int n,x,choice,num;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&x);
    }
    printf("Enter the choice: \n1. Insert at first\n2. Insert at last\n3. Delete a node\n4. Display the list\n5. Exit\n");
    scanf("%d",&choice);
    switch (choice) {
       while (choice != 5) {
            case 1:
                printf("Enter the value to insert at first: ");
                scanf("%d", &x);
                insertAtFirst(x);
                break;
            case 2:
                printf("Enter the value to insert at last: ");
                scanf("%d", &x);
                insertAtLast(x);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &num);
                Delete(num);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
    }
}
}

