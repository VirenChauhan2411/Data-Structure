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

int findHeight(struct TreeNode *root) {
    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    if (leftHeight - rightHeight > 1 ||
        rightHeight - leftHeight > 1)
        return -1;

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

int isBalanced(struct TreeNode *root) {
    return findHeight(root) != -1;
}

int main() {
    struct TreeNode *root;

    printf("Enter tree in preorder (-1 for NULL): ");
    root = createTree();

    if (isBalanced(root))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
