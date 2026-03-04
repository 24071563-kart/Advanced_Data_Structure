#include <stdio.h>
#include <stdlib.h>
struct Node {
    int bookID;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bookID = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->bookID)
        root->left = insert(root->left, id);
    else if (id > root->bookID)
        root->right = insert(root->right, id);

    return root;
}
struct Node* search(struct Node* root, int id) {
    if (root == NULL || root->bookID == id)
        return root;

    if (id < root->bookID)
        return search(root->left, id);
    else
        return search(root->right, id);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->bookID)
        root->left = deleteNode(root->left, id);
    else if (id > root->bookID)
        root->right = deleteNode(root->right, id);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->bookID = temp->bookID;
        root->right = deleteNode(root->right, temp->bookID);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->bookID);
        inorder(root->right);
    }
}

void printRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->bookID > low)
        printRange(root->left, low, high);

    if (root->bookID >= low && root->bookID <= high)
        printf("%d ", root->bookID);

    if (root->bookID < high)
        printRange(root->right, low, high);
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 1001);
    root = insert(root, 1050);
    root = insert(root, 1025);
    root = insert(root, 1100);
    root = insert(root, 1010);

    printf("Books in Sorted Order:\n");
    inorder(root);

    int searchID = 1025;
    if (search(root, searchID))
        printf("\n\nBook ID %d found in library.", searchID);
    else
        printf("\n\nBook ID %d not found.", searchID);

    root = deleteNode(root, 1050);
    printf("\n\nAfter deleting Book ID 1050:\n");
    inorder(root);

    printf("\n\nBooks between ID 1000 and 1050:\n");
    printRange(root, 1000, 1050);

    return 0;
}
