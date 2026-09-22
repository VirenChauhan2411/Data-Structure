#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack[N];
int top  = -1;

void display() 
{
    for(int i = top;i>0;i--)
    {
        printf("%d \n",stack[i]);
    }
}
void push(int x) {
  if (top > N) {
    printf("Stack is overflow...");
    return;
  }
  stack[++top] = x;
}
int pop() 
{
    if(top<=0)
    {
        printf("stack is underflow:");
    }
  int temp = stack[top];
  top--;
  printf("Popped element: %d\n", temp);
  return 0;

}
int peep(int i) 
{
    if(i<0 && i>top)
    {
        printf("dont get output : ");
    }
    return stack[top-i+1];
    display();
}
void change(int i, int val) 
{
    stack[top-i+1] = val;
}

int main() {
  int n;
  printf("Enter the elements in stack: ");
  top = 4;
 do{

    printf("Enter the Operation to be performed: \n1. Push\n2. Pop\n3. "
           "Peep\n4. Change\n5. Display\n6. exit");
    scanf("%d", &n);

    switch (n) {
    case 1:
      printf(":Enter the Number :");
      scanf("%d", &n);
      push(n);
      break;
    case 2:
      pop();
      break;
    case 3:
      printf(":Enter the position to peep:");
      scanf("%d", &n);
      peep(n);
      break;
    case 4:
      printf(":Enter the position to change:");
      scanf("%d", &n);
      {
        int val;
        printf(":Enter the new value:");
        scanf("%d", &val);
        change(n, val);
      }
      break;
    case 5:
      display();
      break;
    case 6:
      
      break;
    }
  }
  while(n!=6);
  return 0;
}