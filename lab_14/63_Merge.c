#include <stdio.h>

int top = -1;
char stack[100];

void push(char x){

    stack[++top] = x;
}

char pop(){

    if (top == -1){

        return '\0';
    }
           
    return stack[top--];
}

int main(){

    int arr[2][2];
    printf("Enter the element in an array : ");
    
    for(int i=0 ; i<2 ; i++){

        for(int j=0 ; j<2 ; j++){

            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0 ; i<2 ; i++){

        for(int j=0 ; j<2 ; j++){

            printf("[%d,%d]", arr[i][0],arr[i][1]);
        }
    }
}