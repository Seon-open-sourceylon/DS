#include <stdio.h>
#include <conio.h>

#define MAX 10  // Maximum number of vertices

int adj[MAX][MAX];   // Adjacency matrix to store the graph
int visited[MAX];    // Array to track visited vertices
int stack[MAX];      // Stack to assist with DFS
int top = -1;        // Top pointer for the stack
int n;               // Number of vertices

// Function to push an element onto the stack
void push(int v) {
    if (top < MAX - 1) {
        stack[++top] = v;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Depth First Search (DFS) function
void DFS(int v) {
    push(v);  // Start by pushing the initial vertex

    while (top != -1) {  // Continue until the stack is empty
        int node = pop();  // Pop the top element

        if (!visited[node]) {  // If the node is not visited
            printf("%d ", node);  // Print the node
            visited[node] = 1;    // Mark the node as visited

            // Push all adjacent unvisited nodes to the stack
            for (int i = n - 1; i >= 0; i--) {
                if (adj[node][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}

int main() {
    int v, i, j;

    clrscr();  // Clear the console screen

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited and adjacency matrix
    for (i = 0; i < n; i++) {
        visited[i] = 0;  // Set all vertices as unvisited
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;  // Initialize adjacency matrix with 0s
        }
    }

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Print the entered adjacency matrix
    printf("\nThe entered adjacency matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // Input the starting vertex for DFS
    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &v);

    // Perform DFS from the given starting vertex
    printf("Depth First Search starting from vertex %d: ", v);
    DFS(v);

    getch();  // Wait for user input before closing
    return 0;
}

