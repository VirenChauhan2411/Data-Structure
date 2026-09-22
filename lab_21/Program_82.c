#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertNode(struct TreeNode *root, int data) {
    if (root == NULL) {
        root = malloc(sizeof(struct TreeNode));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int findSmallest(struct TreeNode *root) {
    if (root->left == NULL)
        return root->data;

    return findSmallest(root->left);
}

int findLargest(struct TreeNode *root) {
    if (root->right == NULL)
        return root->data;

    return findLargest(root->right);
}

int main() {
    struct TreeNode *root;
    int count;
    int data;
    int i;

    root = NULL;

    printf("Enter number of values: ");
    scanf("%d", &count);

    printf("Enter values: ");
    for (i = 0; i < count; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }

    printf("Smallest = %d\n", findSmallest(root));
    printf("Largest = %d\n", findLargest(root));

    return 0;
}
