#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data);
void insertSorted(Node** head, int data);
void displayList(Node* head);
void reverseList(Node** head);

int main()
{
    Node* head = NULL;
    int choice, data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete specified element\n");
        printf("4. Display all elements\n");
        printf("5. Reverse the list\n");
        printf("6. Sort in ascending order\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert element in sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            reverseList(&head);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            printf("Enter a number : ");
            scanf("%d", &data);
            insertSorted(&head, data);
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;
    return node;
}


void insertSorted(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* current = *head;
    Node* prev = newNode;
    while (current != NULL && current->data < newNode->data)
    {
        prev = current;
        current = current->next;
    }

    newNode->next = current;
    if (prev == newNode)
    {
        *head = newNode;
    }
    else
    {
        prev->next = newNode;
    }
}


void displayList(Node* head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Linked list elements: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\t\t      ^\n\t\t      |\n\t\t     HEAD\n");
}


void reverseList(Node** head)
{
    if (*head == NULL)
    {
        return;
    }

    Node* current = *head;
    Node* prev = NULL;
    Node* next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}


void deleteNode(Node** head, int data)
{
    if (*head == NULL)
    {
        return;
    }
    // unfinished
    Node* current = *head;
    while (current != NULL)
    {
        if (current->data == data)
        {

        }
    }
}

