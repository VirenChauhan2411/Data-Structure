#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int findPosition(int inorder[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }

    return -1;
}

struct Node* solve(int inorder[], int postorder[],int *postIndex,int inorderStart,int inorderEnd,int n)
{
    // Base case
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Last element of postorder is root
    int element = postorder[*postIndex];

    (*postIndex)--;

    struct Node* root = newNode(element);

    // Find root in inorder
    int position = findPosition(inorder, element, n);

    // RIGHT subtree first
    root->right = solve(inorder, postorder,postIndex,position + 1,inorderEnd,n);

    // LEFT subtree
    root->left = solve(inorder, postorder,postIndex,inorderStart,position - 1,n);

    return root;
}

struct Node* buildTree(int inorder[], int postorder[], int n)
{
    int postIndex = n - 1;

    return solve(inorder, postorder,&postIndex,0,n - 1,n);
}

void preorder(struct Node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    int n = 6;

    struct Node* root = buildTree(inorder, postorder, n);

    printf("Preorder: ");
    preorder(root);

    return 0;
}