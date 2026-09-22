// WAP to check whether 2 singly linked lists are same or not.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int info;
  struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

int compare(struct node *first1, struct node *first2)
{
  struct node *save1 = first1;
  struct node *save2 = first2;
  while (save1 != NULL && save2 != NULL) 
  {
    if (save1->info != save2->info)
    {
        return 0;
    } 
    save1 = save1->link;
    save2 = save2->link;
  }
  return (save1 == NULL && save2 == NULL); 
}


struct node* insertFirst(struct node *first, int x)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL) 
  {
    return first;
  }
  newNode->info = x;
  newNode->link = first;
  return newNode;
}
void display(struct node *first) 
{
  struct node *save = first;
  while (save != NULL) 
{
    printf("%d\n", save->info);
    save = save->link;
  }
}
int main() 
{
  int n1, n2, x;
  printf("Enter the size of first list: ");
  scanf("%d", &n1);
  printf("Enter the value: ");
  for (int i = 0; i < n1; i++) 
  {
    scanf("%d", &x);
    first1 = insertFirst(first1, x);
  }
  printf("Enter the size of second list: ");
  scanf("%d", &n2);
  printf("Enter the value: ");

  for (int i = 0; i < n2; i++) 
  {
    scanf("%d", &x);
    first2 = insertFirst(first2, x);
  }
  if (compare(first1, first2))
    {
        printf("======== same ========");
    }  
  else
    {
      printf("The two lists are not the same.");
    }
}
