#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void change(){
    struct node *save=first;
    while(save!=NULL && save->link!=NULL)
    {
        int temp;
        temp=save->info;
        save->info=save->link->info;
        save->link->info=temp;
        save=save->link->link;
    }
}
void display(){
    struct node *save=first;
    while(save!=NULL){
        printf("%d",save->info);
        save=save->link;
    }
}
void main(){
    int n;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Number of nodesss.....");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("Enter info:");
        scanf("%d",&new->info);
        new->link=NULL;
        if(first==NULL){
            first=new;
            temp=first;
        }
        else{
            temp->link=new;
            temp=new;
        }
    }
    change();
    display();
}

