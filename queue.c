#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// Function to add an element to the queue
void enqueue() {
    int element;
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;  // Initialize front on the first enqueue
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &element);
    queue[++rear] = element;
    printf("Inserted %d\n", element);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    int data = queue[front];
    if (front == rear) {
        // Reset the queue when last element is dequeued
        front = rear = -1;
    } else {
        front++;
    }
    printf("Dequeued value: %d\n", data);
}

// Function to display the front element
void peek() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Front value: %d\n", queue[front]);
}

// Function to display all elements of the queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue is: \n");
    int temp = front;
    while (1) {
        printf("%d ", queue[temp]);
        if (temp == rear) {
            break;
        }
        temp++;
        if (temp == MAX) {
            temp = 0;  // Wrap around for circular queue
        }
    }
    printf("\n");
}

// Main function to manage queue operations
int main() {
    clrscr();
    int choice;

    printf("Enter a choice to perform queue functions:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display Queue\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
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
                display();
                break;
            case 5:
                printf("Exiting...\n");
                getch();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    getch();  // Wait for user input before closing
    return 0;
}
