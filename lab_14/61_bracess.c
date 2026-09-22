#include<stdio.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[--top] = ch;
}

char pop()
{
    return stack[top--];
}
int isValid(char s[])
{
    for (int i=0; s[i]!='\0'; i++) 
    {
        if (    (s[i] =='(')     ||      (s[i] =='[')   ||      (s[i] =='{')     ) 
        {
            push(s[i]);
        }
        else if(    (s[i] ==')')     ||     (s[i] ==']')    ||      (s[i] =='}')     ) 
        {
        
            char forpop = pop();
            
            if ((forpop == '(' && s[i] ==')') || (forpop == '[' && s[i] ==']') || (forpop == '{' && s[i] =='}') ) 
            {
                continue;
            }
            else 
            {
                return 0;
            }
        }
    }

    if (top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


