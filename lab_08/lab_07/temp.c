#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>


// Node structure
struct Node 
{
    int info;
    struct Node* link;
};

struct Node* first = NULL;

// Function to insert at front

void insertFront(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

// Function to display all nodes

void display() {
    struct Node* temp = first;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);

        temp = temp->link;
    }
    printf("NULL\n");
}

// Function to delete first 

void deleteFront()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;
    first = first->link;
    free(temp);
    printf("First node deleted.\n");
}

// Function to insert at end

void insertEnd(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
        return;
    }

    struct Node* temp = first;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Function to delete last node
void deleteEnd() 
{
    if (first == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    if (first->link == NULL) 
    {
        free(first);
        first = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* temp = first;
    while (temp->link->link != NULL) 
    {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    printf("Last node deleted.\n");
}

// Function to delete node at specified position

void deleteAtPosition(int pos) 
{
    if (first == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) 
    {
        deleteFront();
        return;
    }

    struct Node* temp = first;
    for (int i = 1; temp != NULL && i < pos - 1; i++) 
    {
        temp = temp->link;
    }

    if (temp == NULL || temp->link == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->link;
    temp->link = delNode->link;
    free(delNode);
    printf("Node at position %d deleted.\n", pos);
}

// Function to count nodes
void countNodes() 
{
    int count = 0;
    struct Node* temp = first;
    while (temp != NULL) 
    {
        count++;
        temp = temp->link;
    }
    printf("Total nodes: %d\n", count);
}

// Main function with menu

int main() 
{
    int choice, x, pos;
    while (1) 
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Display\n");
        printf("3. Delete Front\n");
        printf("4. Insert at End\n");
        printf("5. Delete End\n");
        printf("6. Delete at Position\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter x: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                printf("Enter x: ");
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                countNodes();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
