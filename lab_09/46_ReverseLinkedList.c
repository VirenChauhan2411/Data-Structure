#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *link;
};
struct node *first1 = NULL;
struct node *first2 = NULL;

void reverse() 
{
  struct node *save1 = first1;
  struct node *save2 = first2;
  while (save1 != NULL) 
  {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = save1->info;
    new->link = first2;
    first2 = new;
    save2 = first2;
    save1 = save1->link;
  }
}
void display() 
{
  struct node *save2 = first2;
  while (save2 != NULL) {
    printf("%d \n", save2->info);
    save2 = save2->link;
  }
}
void main() {
  int n;
  printf("Enter number of nodes:");
  scanf("%d", &n);
  struct node *save1;
  for (int i = 0; i < n; i++) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter info:");
    scanf("%d", &new->info);
    new->link = NULL;
    if (first1 == NULL) {
      first1 = new;
      save1 = first1;
    } else {
      save1->link = new;
      save1 = new;
    }
  }
  reverse();
  display();
}