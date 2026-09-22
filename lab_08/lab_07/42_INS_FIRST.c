#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>


struct Node {
    int info;
    struct Node* link;
};
       struct Node* first = NULL;

void insertFirst(int x){

      struct Node* new;
      new = (struct Node*)malloc(sizeof(struct Node));

      new->info = x;
    new->link = first;
      
      first = new;

}
void dispay()
{
    struct node*save = first;
    while (save!=NULL) {
        printf("%d\n",save->info);
        save = save ->link;
    }
}
void main()
{
    int n,x;
    printf("Enter the size of list : ");
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
    printf("Enter the value :");
    scanf("%d",&x);
    insertFirst(x);
    }
    dispay();
}

