#include <stdio.h>
#include <stdlib.h>

struct TwoThreeNode {
    int firstKey;
    int secondKey;
    int keyCount;
    struct TwoThreeNode *left;
    struct TwoThreeNode *middle;
    struct TwoThreeNode *right;
};

struct TwoThreeNode *createNode(int firstKey) {
    struct TwoThreeNode *node;

    node = malloc(sizeof(struct TwoThreeNode));
    node->firstKey = firstKey;
    node->secondKey = 0;
    node->keyCount = 1;
    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;

    return node;
}

int searchTree(struct TwoThreeNode *root, int value) {
    if (root == NULL)
        return 0;

    if (value == root->firstKey)
        return 1;

    if (root->keyCount == 2 && value == root->secondKey)
        return 1;

    if (root->keyCount == 1) {
        if (value < root->firstKey)
            return searchTree(root->left, value);

        return searchTree(root->right, value);
    }

    if (value < root->firstKey)
        return searchTree(root->left, value);

    if (value < root->secondKey)
        return searchTree(root->middle, value);

    return searchTree(root->right, value);
}

void displayTree(struct TwoThreeNode *root) {
    if (root == NULL)
        return;

    printf("[");
    printf("%d", root->firstKey);

    if (root->keyCount == 2)
        printf(" %d", root->secondKey);

    printf("] ");

    displayTree(root->left);
    displayTree(root->middle);
    displayTree(root->right);
}

int main() {
    struct TwoThreeNode *root;
    int first;
    int second;
    int searchValue;

    root = NULL;

    printf("Enter first key: ");
    scanf("%d", &first);

    root = createNode(first);

    printf("Enter second key for the same node: ");
    scanf("%d", &second);

    if (second > first) {
        root->secondKey = second;
        root->keyCount = 2;
    }

    printf("Enter value to search: ");
    scanf("%d", &searchValue);

    if (searchTree(root, searchValue))
        printf("Found\n");
    else
        printf("Not found\n");

    printf("Tree: ");
    displayTree(root);
    printf("\n");

    return 0;
















