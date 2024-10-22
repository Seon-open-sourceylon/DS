#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int n) {
    if (top < MAX - 1) {
        stack[++top] = n;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return 0;
    }
}

// Function to evaluate an operation based on the given operator
int evaluate(char ch, int op1, int op2) {
    switch (ch) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default:
            printf("Invalid operator: %c\n", ch);
            return 0;
    }
}

// Main function to evaluate a postfix expression
int main() {
    clrscr();
    char expression[50];
    int i, op1, op2, result;

    printf("Enter a postfix expression to evaluate: \n");
    gets(expression);

    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            push(ch - '0'); // Convert character to integer
        } else if (ch == ' ' || ch == '\n') {
            continue; // Skip spaces or newlines
        } else {
            op2 = pop();
            op1 = pop();
            result = evaluate(ch, op1, op2);
            push(result);
        }
    }

    result = pop();
    printf("Evaluation result is: %d\n", result);

    getch();
    return 0;
}
