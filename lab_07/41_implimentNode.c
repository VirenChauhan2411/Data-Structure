#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>


struct Node {
    int info;
    struct Node* link;
};
       struct Node* first = NULL;

void insertFirst(int x){

      struct Node* NewNode;
      NewNode = (struct Node*)malloc(sizeof(struct Node));

      NewNode->info = x;
    NewNode->link = first;
      
      first = NewNode;

}
void dispay()
{
    struct Node* save = first;
    while (save != NULL) {
        printf("%d\n", save->info);
        save = save->link;
    }
}
void main()
{
    int n,x;
    printf("Enter the size of list : ");
    scanf("%d",&n);
        printf("Enter the value :");

    for (int i=0; i<n; i++) {
    scanf("%d",&x);
    insertFirst(x);
    }
    dispay();
}

