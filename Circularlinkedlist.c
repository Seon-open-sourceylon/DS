#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// Function to insert a node at the beginning
void InsertAtBeginning(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;  // Self-loop for a single-node circular list
    } else {
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;  // Update head to the new node
    }
}

// Function to insert a node at the end
void InsertAtEnd(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
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
        if (temp->next == head) {
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
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    node *toDelete = head;
    temp->next = head->next;
    head = head->next;
    free(toDelete);
}

// Function to delete a node from the end
void DeleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
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
        if (temp->next == head) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("Cannot delete the head node using this function.\n");
        return;
    }

    node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to display the circular linked list
void Display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    printf("List contents:\n");
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Main function to drive the circular linked list operations
int main() {
    int ch, data, position;

    clrscr();  // Clear the console

    printf("Circular Linked List Menu:\n");
    printf("1. Insert At Beginning\n");
    printf("2. Insert At End\n");
    printf("3. Insert At Position\n");
    printf("4. Delete At Beginning\n");
    printf("5. Delete At End\n");
    printf("6. Delete At Position\n");
    printf("7. Display\n");
    printf("8. Exit\n");

    while (1) {
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
                Display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
        printf("\n");
    }

    getch();  // Wait for user input before closing the console
    return 0;
}

