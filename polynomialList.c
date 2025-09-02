#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int pow;
    struct Node *prev, *next;
};

// Create a new node
struct Node* createNode(int c, int p) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coef = c;
    newnode->pow = p;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

// Insert node at end
void insertEnd(struct Node** head, int c, int p) {
    struct Node* newnode = createNode(c, p);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

// Display polynomial
void displayPoly(struct Node* head) {
    if (!head) {
        printf("0");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coef);
        if (temp->pow != 0)
            printf("x^%d", temp->pow);
        if (temp->next != NULL && temp->next->coef >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
}

// Add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insertEnd(&result, p1->coef, p1->pow);
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow) {
            insertEnd(&result, p2->coef, p2->pow);
            p2 = p2->next;
        }
        else {
            int sum = p1->coef + p2->coef;
            if (sum != 0)
                insertEnd(&result, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertEnd(&result, p1->coef, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertEnd(&result, p2->coef, p2->pow);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    int n1, n2, coef, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms of polynomial 1 (coef pow) in descending order:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coef, &pow);
        insertEnd(&poly1, coef, pow);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms of polynomial 2 (coef pow) in descending order:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coef, &pow);
        insertEnd(&poly2, coef, pow);
    }

    sum = addPoly(poly1, poly2);

    printf("\nPolynomial 1: ");
    displayPoly(poly1);
    printf("\nPolynomial 2: ");
    displayPoly(poly2);
    printf("\nSum: ");
    displayPoly(sum);
    printf("\n");

    return 0;
}
