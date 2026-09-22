#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int x)
{
    if (top ==  100)
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

int main()
{
    char input[100];
    printf("Enter postfix exp: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            push(input[i] - '0');
        }
        else
        {
            int m = pop();
            int n = pop();
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

    printf("Ans = %d\n", pop());
    return 0;
}