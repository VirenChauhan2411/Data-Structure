#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneEntry {
    char name[50];
    char phone[20];
    struct PhoneEntry *left;
    struct PhoneEntry *right;
};

struct PhoneEntry *createEntry(char name[], char phone[]) {
    struct PhoneEntry *entry;

    entry = malloc(sizeof(struct PhoneEntry));
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
    entry->left = NULL;
    entry->right = NULL;

    return entry;
}

struct PhoneEntry *addEntry(struct PhoneEntry *root,
                            char name[], char phone[]) {
    if (root == NULL)
        return createEntry(name, phone);

    if (strcmp(name, root->name) < 0)
        root->left = addEntry(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = addEntry(root->right, name, phone);
    else
        strcpy(root->phone, phone);

    return root;
}

struct PhoneEntry *searchEntry(struct PhoneEntry *root, char name[]) {
    if (root == NULL)
        return NULL;

    if (strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return searchEntry(root->left, name);

    return searchEntry(root->right, name);
}

struct PhoneEntry *findSmallest(struct PhoneEntry *root) {
    if (root->left == NULL)
        return root;

    return findSmallest(root->left);
}

struct PhoneEntry *deleteEntry(struct PhoneEntry *root, char name[]) {
    struct PhoneEntry *smallest;

    if (root == NULL)
        return NULL;

    if (strcmp(name, root->name) < 0) {
        root->left = deleteEntry(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteEntry(root->right, name);
    } else {
        if (root->left == NULL) {
            struct PhoneEntry *right = root->right;
            free(root);
            return right;
        }

        if (root->right == NULL) {
            struct PhoneEntry *left = root->left;
            free(root);
            return left;
        }

        smallest = findSmallest(root->right);
        strcpy(root->name, smallest->name);
        strcpy(root->phone, smallest->phone);
        root->right = deleteEntry(root->right, smallest->name);
    }

    return root;
}

void displayAscending(struct PhoneEntry *root) {
    if (root == NULL)
        return;

    displayAscending(root->left);
    printf("%s : %s\n", root->name, root->phone);
    displayAscending(root->right);
}

void displayDescending(struct PhoneEntry *root) {
    if (root == NULL)
        return;

    displayDescending(root->right);
    printf("%s : %s\n", root->name, root->phone);
    displayDescending(root->left);
}

int main() {
    struct PhoneEntry *root;
    struct PhoneEntry *entry;
    int choice;
    char name[50];
    char phone[20];

    root = NULL;

    do {
        printf("\n1 Add\n2 Remove\n3 Search\n4 Ascending\n5 Descending\n0 Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%49s %19s", name, phone);
            root = addEntry(root, name, phone);
        } else if (choice == 2) {
            scanf("%49s", name);
            root = deleteEntry(root, name);
        } else if (choice == 3) {
            scanf("%49s", name);
            entry = searchEntry(root, name);

            if (entry != NULL)
                printf("%s\n", entry->phone);
            else
                printf("Entry not found\n");
        } else if (choice == 4) {
            displayAscending(root);
        } else if (choice == 5) {
            displayDescending(root);
        }
    } while (choice != 0);

    return 0;
}
