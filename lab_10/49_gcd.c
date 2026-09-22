#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
int min(int n,int m){
    if(n<m){
        return n;
    }
    else{
        return m;
    }
}
void gcd(){
    struct node *save=first;
    while(save->link->link!=NULL)
     {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        int i=min(save->info,save->link->info);
        while(i>0){
            if(save->info%i==0 && save->link->info%i==0){
                new->info=i;
                new->link=save->link;
                save->link=new;
                break;
            }
            i--;
        }
        save=save->link->link;
    }
}
void display(){
    struct node *save=first;
    while(save!=NULL){
        printf("%d \n",save->info);
        save=save->link;
    }
}
void main(){
    int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);
    struct node *temp=first;
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
    gcd();
    display();
}   