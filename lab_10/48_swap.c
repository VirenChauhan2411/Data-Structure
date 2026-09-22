#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
void replace(int n)
{
    struct node *save = first;
    int k, i = 1, temp,x2,x;
    printf("ENter k:");
    scanf("%d", &k);
    for(save=first;save!=NULL;save=save->link){
        if(i==k){
            temp=save->info;
        }
        if(i==n-k+1){
            x = save->info;
            save->info=temp;
            temp=x;
        }
        i++;
    }
    i=1;
    for(save=first;save!=NULL;save=save->link){
        if(i==k){
            save->info=temp;
        }
        i++;
    }
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
void main()
{
    int n;
    printf("Enter number of nodes...:");
    scanf("%d", &n);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; i < n; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        printf("ENter info:");
        scanf("%d", &new->info);
        new->link = NULL;
        if (first == NULL)
        {
            first = new;
            temp = new;
        }
        else
        {
            temp->link = new;
            temp = new;
        }
    }
    replace(n);
    display();
}