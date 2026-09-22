#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree() {
    int data;
    struct TreeNode *node;

    scanf("%d", &data);

    if (data == -1)
        return NULL;

    node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = createTree();
    node->right = createTree();

    return node;
}

int areTreesSame(struct TreeNode *first, struct TreeNode *second) {
    if (first == NULL && second == NULL)
        return 1;

    if (first == NULL || second == NULL)
        return 0;

    if (first->data != second->data)
        return 0;

    return areTreesSame(first->left, second->left) &&
           areTreesSame(first->right, second->right);
}

int main() {
    struct TreeNode *firstTree;
    struct TreeNode *secondTree;

    printf("Enter first tree in preorder (-1 for NULL): ");
    firstTree = createTree();

    printf("Enter second tree in preorder (-1 for NULL): ");
    secondTree = createTree();

    if (areTreesSame(firstTree, secondTree))
        printf("Given trees are same\n");
    else
        printf("Given trees are not same\n");

    return 0;
}
