#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int n){

    struct node *new = NULL;
    new = (struct node *)malloc(sizeof(struct node));

    new->data = n;
    new->next = top;
    top = new;

}

void pop(){

    struct node *temp = NULL ;
    temp = (struct node*)malloc(sizeof(*temp));

    if(top == NULL){

        printf("Stack is underflow.");
    }

    temp = top;
    top = top->next;
    free(temp);
    
}

int peak(){

    if(top == NULL){

        printf("Stack is empty.");
    }

    return top->data;
}

void display(){

    if(top == NULL){

        printf("Stack is empty.");
    }
    
    while(top != NULL){

        printf("%d ", top->data);
        top = top -> next;
    }
}

int main(){

    int n,choice;

    do{

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
            printf("Enter the value which you want to push in stack: ");
            scanf("%d",&n);
            push(n);
            break;

            case 2:
            pop();
            break;

            case 3:
            peak();
            break;

            case 4:
            display();
            break;

            case 5:
            printf("Operations are over here.");
            break;

            default:
            printf("Invalid input");
            break;

        }
    }while(choice != 5);

    return 0;

}