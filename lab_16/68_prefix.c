#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

int stack[100];
int top = -1;

void push(int x)
{
    if (top == 100)
    {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}




int evaluation_prifix(char input[]){
    for (int i = strlen(input) -1; i >= 0; i--)
    {
        if (isdigit(input[i]))
        {
            push(input[i] - '0');
        }
        else
        {
            int n = pop();
            int m = pop();
            int result;

            switch (input[i])
            {
                case '+':
                    result = n + m;
                    break;

                case '-':
                    result = n - m;
                    break;

                case '*':
                    result = n * m;
                    break;

                case '/':
                    result = n / m;
                    break;

                case '^':
                    result = n ^ m;
                    break;

                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            push(result);
        }
    }
    int x = pop();
    printf("Ans = %d\n",x);
    return x;
}
int main()
{
    char input[100];
    printf("Enter postfix exp: ");
    scanf("%s", input);
    int ans = evaluation_prifix(input);

    
}