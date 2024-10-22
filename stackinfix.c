#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define MAX 50

char stack[MAX];
int top = -1;

// Function to push an item onto the stack
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop an item from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0'; // Return null character if stack is empty
    } else {
        return stack[top--];
    }
}

// Function to determine precedence of operators
int Precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
void convert(char infix[], char postfix[]) {
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c)) {  // If operand, add to postfix
            postfix[j++] = c;
        } else if (c == '(') {  // If '(', push to stack
            push(c);
        } else if (c == ')') {  // If ')', pop until '(' is found
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();  // Remove '(' from stack
            }
        } else {  // Operator encountered
            while (top != -1 && Precedence(stack[top]) >= Precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);  // Push current operator onto stack
        }
        i++;
    }

    // Pop remaining operators from stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    clrscr();  // Clear the console
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    gets(infix);  // Get infix expression from user

    convert(infix, postfix);  // Convert to postfix

    printf("Postfix expression is:\n");
    for (int i = 0; i < strlen(postfix); i++) {
        printf("%c", postfix[i]);
    }

    getch();  // Wait for user input
    return 0;
}

