#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = *top;
    *top = temp;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            push(&stack, c - '0');
        } else {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            int result;
            switch (c) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
                default: printf("Unknown operator: %c\n", c); exit(1);
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, 100, stdin);
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}
