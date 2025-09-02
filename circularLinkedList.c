#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *first = NULL, *last = NULL;

// Insert at end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL) { 
        first = last = newNode;
        last->next = first;
    } else {
        last->next = newNode;
        last = newNode;
        last->next = first;
    }
    printf("\nInserted %d at end.\n", value);
}

// Deletion from beginning
void deleteBeginning() {
    if (first == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = first;

    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }

    printf("\nDeleted %d from beginning.\n", temp->data);
    free(temp);
}

// Deletion from end
void deleteEnd() {
    if (first == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = first;

    if (first == last) { 
        printf("\nDeleted %d from end.\n", first->data);
        free(first);
        first = last = NULL;
        return;
    }

    while (temp->next != last) { 
        temp = temp->next;
    }

    printf("\nDeleted %d from end.\n", last->data);
    free(last);
    last = temp;
    last->next = first;
}

// Display circular list
void displayList() {
    if (first == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct Node* temp = first;
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("(back to %d)\n", first->data);
}

int main() {
    int choice, value;

    do {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            displayList();
            break;
        case 2:
            deleteBeginning();
            displayList();
            break;
        case 3:
            deleteEnd();
            displayList();
            break;
        case 4:
            displayList();
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
