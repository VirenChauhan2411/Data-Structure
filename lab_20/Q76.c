#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insertnode(void) {
    int data;
    printf("");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        return NULL;
    }

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    printf(" enter data on left of %d", data);
    newnode->left = insertnode();

    printf(" enter data on right of %d", data);
    newnode->right = insertnode();

    return newnode;
}