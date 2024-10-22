#include <stdio.h>
#include <conio.h>

#define Max 2  // Maximum size of the queue

int queue[Max];  // Array to implement the queue
int rear = -1;   // Rear pointer of the queue
int front = -1;  // Front pointer of the queue

// Function to insert an element into the queue
void enqueue() {
    int num;
    if (rear == Max - 1) {  // Check if the queue is full
        printf("Queue is full\n");
    } else {
        printf("Enter the data to be inserted: ");
        scanf("%d", &num);
        if (front == -1) {  // If queue is initially empty
            front = 0;
        }
        rear++;
        queue[rear] = num;  // Insert the element
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {  // Check if the queue is empty
        printf("Queue is empty\n");
    } else {
        printf("The deleted element is %d\n", queue[front]);
        front++;
        if (front > rear) {  // Reset queue if it becomes empty
            front = rear = -1;
        }
    }
}

// Function to display the front element of the queue
void peek() {
    if (front == -1 || front > rear) {  // Check if the queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Main function to drive the queue operations
void main() {
    int choice;
    clrscr();  // Clear the console screen

    printf("*******QUEUE******\n");
    while (1) {
        printf("\n1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. EXIT\n");
        printf("Select the operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                return;  // Exit the program
            default:
                printf("INVALID CHOICE\n");
        }
    }
    getch();  // Wait for user input before closing the console
}
