


//Write a program to convert infix notation to postfix notation using stack.


char stack[100];

int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int IPF(char ch)
{
  if (ch == '+' || ch == '-') {
    return 1;
  }
  else if (ch == '*' || ch == '/')
  {
    return 3;
  }
  else if (ch == '^')
  {
    return 6;
  }
  else if (ch == '(')
  {
    return 9;
  }
  else if (ch == ')')
  {
    return 0;
  }
  else
  {
    return 7;
  }
}
int SPF(char ch)
{
   if (ch == '+' || ch == '-')
   {
    return 2;
  } 
  else if (ch == '*' || ch == '/') 
  {
    return 4;
  } 
  else if (ch == '^') 
  {
    return 5;
  } 
  else if (ch == '(') 
  {
    return 0;
  } 
  else {
  return 8;
  }
}
int rank(char ch)
{

}

char postfix[100];
int k = 0;

int infix_to_postfix(char s[])
{
  
}


int main()
{
   char string[100];
    printf("Enter the elements : ");
    scanf("%s",string);
    infix_to_postfix(string);
}
