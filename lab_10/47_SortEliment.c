#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct node {
  int info;
  struct node *link;
};
struct node *first = NULL;
void sort() {
  struct node *save1 = first;
  struct node *save2;
  for (save1 = first; save1 != NULL; save1 = save1->link) 
  {
    for (save2 = first; save2->link != NULL; save2 = save2->link) 
    {
      if (save2->info > save2->link->info) 
      {
        int temp = save2->info;
        save2->info = save2->link->info;
        save2->link->info = temp;
      }
    }
  }
}
void display() {
  struct node *save = first;
  while (save != NULL) {
    printf("%d \n", save->info);
    save = save->link;
  }
}
void main() {
  int n;
  printf("ENter number of nodes:");
  scanf("%d", &n);
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  for (int i = 1; i <= n; i++) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter info:");
    scanf("%d", &new->info);
    new->link = NULL;
    if (first == NULL) {
      first = new;
      temp = first;
    } else {
      temp->link = new;
      temp = new;
    }
  }
  sort();
  display();
}