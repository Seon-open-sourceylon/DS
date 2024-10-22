#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Definition of a Node in the Linked List
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;  // Head pointer to the linked list

// Function to insert a node at the beginning
void InsertAtBeginning(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at the end
void InsertAtEnd(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to insert a node at a specific position
void InsertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    if (position == 1) {
        InsertAtBeginning(data);
        return;
    }

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;

    node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete a node from the beginning
void DeleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the end
void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a specific position
void DeleteAtPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("Position out of bounds or list is empty\n");
        return;
    }
    if (position == 1) {
        DeleteAtBeginning();
        return;
    }

    node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    node *nodeToDelete = temp->next;
    if (nodeToDelete == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function to manage linked list operations
int main() {
    clrscr();  // Clear the console screen

    int ch, data, position;

    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Position\n");
        printf("4. Delete At Beginning\n");
        printf("5. Delete At End\n");
        printf("6. Delete At Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data you want to insert:\n");
                scanf("%d", &data);
                InsertAtBeginning(data);
                break;
            case 2:
                printf("Enter the data you want to insert:\n");
                scanf("%d", &data);
                InsertAtEnd(data);
                break;
            case 3:
                printf("Enter the position and the data you want to insert:\n");
                scanf("%d %d", &position, &data);
                InsertAtPosition(data, position);
                break;
            case 4:
                DeleteAtBeginning();
                break;
            case 5:
                DeleteAtEnd();
                break;
            case 6:
                printf("Enter the position you want to delete from:\n");
                scanf("%d", &position);
                DeleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                getch();  // Wait for user input before closing
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    }

    getch();  // Wait for user input before closing
    return 0;
}

