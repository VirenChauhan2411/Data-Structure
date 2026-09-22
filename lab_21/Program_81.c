#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findPosition(int postorder[], int start, int end, int value) {
    int i;

    for (i = start; i <= end; i++) {
        if (postorder[i] == value)
            return i;
    }

    return -1;
}

struct TreeNode *buildTree(int preorder[], int postorder[],
                           int preStart, int preEnd,
                           int postStart, int postEnd) {
    struct TreeNode *root;
    int leftRootPosition;
    int leftSize;

    if (preStart > preEnd)
        return NULL;

    root = malloc(sizeof(struct TreeNode));
    root->data = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    if (preStart == preEnd)
        return root;

    leftRootPosition = findPosition(
        postorder, postStart, postEnd, preorder[preStart + 1]);

    leftSize = leftRootPosition - postStart + 1;

    root->left = buildTree(
        preorder, postorder,
        preStart + 1, preStart + leftSize,
        postStart, leftRootPosition);

    root->right = buildTree(
        preorder, postorder,
        preStart + leftSize + 1, preEnd,
        leftRootPosition + 1, postEnd - 1);

    return root;
}

void inorder(struct TreeNode *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int preorder[100];
    int postorder[100];
    int count;
    int i;
    struct TreeNode *root;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    printf("Enter preorder: ");
    for (i = 0; i < count; i++)
        scanf("%d", &preorder[i]);

    printf("Enter postorder: ");
    for (i = 0; i < count; i++)
        scanf("%d", &postorder[i]);

    root = buildTree(preorder, postorder,
                     0, count - 1, 0, count - 1);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
