#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
        printf("%d has been pushed into the stack\n", value);
    }
}

// Function to pop the top element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("%d is popped from the stack\n", stack[top--]);
    }
}

// Function to display the top element without removing it
void peek() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Elements of the stack are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to handle user choices
int main() {
    clrscr();  // Clear console
    int choice, value;

    do {
        printf("\nSelect a choice of operation:\n");
        printf("1. Push\n");
        printf("2. Peek\n");
        printf("3. Pop\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                peek();
                break;
            case 3:
                pop();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    getch();  // Wait for user input before closing
    return 0;
}
