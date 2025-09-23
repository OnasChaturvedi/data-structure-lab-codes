#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char c) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = c;
    temp->next = *top;
    *top = temp;
}

char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char c = temp->data;
    *top = temp->next;
    free(temp);
    return c;
}

char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Node* stack = NULL;
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(&stack, c);
        }
        else if (c == ')') {
            while (peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else {
            while (stack && precedence(peek(stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }
    while (stack) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
