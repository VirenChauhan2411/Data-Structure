#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int color;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
};

struct TreeNode *createNode(int data) {
    struct TreeNode *node;

    node = malloc(sizeof(struct TreeNode));
    node->data = data;
    node->color = 1;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

int getColor(struct TreeNode *node) {
    if (node == NULL)
        return 0;

    return node->color;
}

void rotateLeft(struct TreeNode **root, struct TreeNode *node) {
    struct TreeNode *rightChild;

    rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != NULL)
        rightChild->left->parent = node;

    rightChild->parent = node->parent;

    if (node->parent == NULL)
        *root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;

    rightChild->left = node;
    node->parent = rightChild;
}

void rotateRight(struct TreeNode **root, struct TreeNode *node) {
    struct TreeNode *leftChild;

    leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != NULL)
        leftChild->right->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == NULL)
        *root = leftChild;
    else if (node == node->parent->right)
        node->parent->right = leftChild;
    else
        node->parent->left = leftChild;

    leftChild->right = node;
    node->parent = leftChild;
}

void fixInsertion(struct TreeNode **root, struct TreeNode *node) {
    struct TreeNode *parent;
    struct TreeNode *grandParent;
    struct TreeNode *uncle;

    while (node != *root && getColor(node->parent) == 1) {
        parent = node->parent;
        grandParent = parent->parent;

        if (parent == grandParent->left) {
            uncle = grandParent->right;

            if (getColor(uncle) == 1) {
                parent->color = 0;
                uncle->color = 0;
                grandParent->color = 1;
                node = grandParent;
            } else {
                if (node == parent->right) {
                    node = parent;
                    rotateLeft(root, node);
                    parent = node->parent;
                    grandParent = parent->parent;
                }

                parent->color = 0;
                grandParent->color = 1;
                rotateRight(root, grandParent);
            }
        } else {
            uncle = grandParent->left;

            if (getColor(uncle) == 1) {
                parent->color = 0;
                uncle->color = 0;
                grandParent->color = 1;
                node = grandParent;
            } else {
                if (node == parent->left) {
                    node = parent;
                    rotateRight(root, node);
                    parent = node->parent;
                    grandParent = parent->parent;
                }

                parent->color = 0;
                grandParent->color = 1;
                rotateLeft(root, grandParent);
            }
        }
    }

    (*root)->color = 0;
}

struct TreeNode *insertNode(struct TreeNode *root, int data) {
    struct TreeNode *current;
    struct TreeNode *parent;
    struct TreeNode *node;

    current = root;
    parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return root;
    }

    node = createNode(data);
    node->parent = parent;

    if (parent == NULL)
        root = node;
    else if (data < parent->data)
        parent->left = node;
    else
        parent->right = node;

    fixInsertion(&root, node);

    return root;
}

void preorder(struct TreeNode *root) {
    if (root == NULL)
        return;

    printf("%d(%c) ", root->data, root->color ? 'R' : 'B');
    preorder(root->left);
    preorder(root->right);
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

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}