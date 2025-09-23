#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int len = strlen(str);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != stack[top--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    if (isPalindrome(s)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }
    return 0;
}
