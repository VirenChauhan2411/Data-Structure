#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top  = -1;

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}

void display() 
{
    for(int i = 0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
}
void opration(char s[])
{
    for (int i=0; s[i]!='\0'; i++) 
    {
        if(s[i] != '*')
        {
            push(s[i]);
        }
        else {
           pop();
        }
    }
}
int main()
{
    char string[100];
    printf("Enter the elements : ");
    scanf("%s",string);
    opration(string);
    display();

}