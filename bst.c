#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key into the BST
struct node* insert(struct node *node, int key) {
    if (node == NULL)
        return newNode(key);  // If tree is empty, return a new node

    if (key < node->key) {
        node->left = insert(node->left, key);  // Insert in the left subtree
    } else if (key > node->key) {
        node->right = insert(node->right, key);  // Insert in the right subtree
    }
    return node;  // Return unchanged node pointer
}

// Function to search for a key in the BST
struct node* search(struct node *root, int key) {
    if (root == NULL || root->key == key)  // Base case: root is NULL or key is found
        return root;

    if (key < root->key) {
        return search(root->left, key);  // Search in the left subtree
    } else {
        return search(root->right, key);  // Search in the right subtree
    }
}

// Main function to drive the BST operations
int main() {
    struct node *root = NULL;
    struct node *result;
    int n, key, s, i;

    // Input the number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Input the values to insert into the BST
    printf("Enter values to insert: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Input the key to search in the BST
    printf("Enter the value to search: ");
    scanf("%d", &s);

    // Search for the key and display the result
    result = search(root, s);
    if (result != NULL) {
        printf("Key %d found in the binary tree.\n", s);
    } else {
        printf("Key %d not found in the binary tree.\n", s);
    }

    return 0;
}
