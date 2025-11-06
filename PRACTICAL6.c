#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void search(struct node *root, int key) {
    if (root == NULL)
        printf("NULL\n");
    else if (root->data == key)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node* deleteleaf(struct node *root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteleaf(root->left, key);
    else if (key > root->data)
        root->right = deleteleaf(root->right, key);
    else if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    return root;
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Search\n2. Insert\n3. Delete leaf node\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter values to insert (-1 to stop): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1)
                        break;
                    root = insert(root, value);
                }
                break;

            case 3:
                printf("Enter leaf value to delete: ");
                scanf("%d", &value);
                root = deleteleaf(root, value);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
