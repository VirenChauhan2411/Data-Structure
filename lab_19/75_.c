#include<stdio.h>
#include <stddef.h>

#include<stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
    struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
    printf("1. Insert a node\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
            if (scanf("%d", &choice) != 1) {
                printf("Please enter a number.\n");
                while (getchar() != '\n') {
                }
                continue;
            }
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid data.\n");
                                while (getchar() != '\n') {
                                }
                                break;
                            }
                root = insert(root, data);
                printf("Node inserted successfully\n");
                break;
                
            case 2:
                printf("Enter data to delete: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid data.\n");
                                while (getchar() != '\n') {
                                }
                                break;
                            }
                            if (search(root, data) == NULL) {
                                printf("Node not found.\n");
                                break;
                            }
                root = delete(root, data);
                            printf("Node deleted successfully.\n");
                break;
                
            case 3:
                printf("Enter data to search: ");
                            if (scanf("%d", &data) != 1) {
                                printf("Invalid data.\n");
                                while (getchar() != '\n') {
                                }
                                break;
                            }
                if (search(root, data) != NULL) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found!\n");
                }
                break;
                
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
                
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
                
            case 7:
                printf("Exiting...\n");
                    freeTree(root);
                    return 0;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}