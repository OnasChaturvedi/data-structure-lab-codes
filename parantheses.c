#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int checkBalanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (top == -1) return 0;
            char open = pop();
            if (!isMatching(open, expr[i])) return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (checkBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
