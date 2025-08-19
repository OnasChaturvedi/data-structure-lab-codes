#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
Node* createNode(int data);
void insertLast(Node* header, Node* tail, int data);
void traverseForward(Node* header, Node* tail);
void traverseReverse(Node* header, Node* tail);
void deleteLast(Node* header, Node* tail);
void insertAtPosition(Node* header, Node* tail, int data, int index);
void deleteAtPosition(Node* header, Node* tail, int index);
void insertAdjacentToNode(Node* header, Node* tail, int data, int value, int insertBefore);

int main()
{
    Node* header = createNode(-1); // Header node with dummy data
    Node* tail = createNode(-1);  // Tail node with dummy data
    header->next = tail;
    tail->prev = header;

    int choice, data, index, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert an element at the rear end of the list\n");
        printf("2. Delete an element from the rear end of the list\n");
        printf("3. Insert an element at a given position in the list\n");
        printf("4. Delete an element from a given position in the list\n");
        printf("5. Insert an element after a node containing a specific value\n");
        printf("6. Insert an element before a node containing a specific value\n");
        printf("7. Traverse and display the doubly linked list in forward direction\n");
        printf("8. Traverse and display the doubly linked list in reverse direction\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertLast(header, tail, data);
                break;
            case 2:
                deleteLast(header, tail);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &index);
                insertAtPosition(header, tail, data, index);
                break;
            case 4:
                printf("Enter position to delete from: ");
                scanf("%d", &index);
                deleteAtPosition(header, tail, index);
                break;
            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter value of node to insert after: ");
                scanf("%d", &value);
                insertAdjacentToNode(header, tail, data, value, 0);
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter value of node to insert before: ");
                scanf("%d", &value);
                insertAdjacentToNode(header, tail, data, value, 1);
                break;
            case 7:
                traverseForward(header, tail);
                break;
            case 8:
                traverseReverse(header, tail);
                break;
            case 9:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


// Creates a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Couldn't allocate memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


// Inserts new node at the end
void insertLast(Node* header, Node* tail, int data)
{
    Node* newNode = createNode(data);
    Node* current = header;
    while (current->next != tail)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
    newNode->next = tail;
    tail->prev = newNode;
}


// Delete node from the end
void deleteLast(Node* header, Node* tail)
{
    if (header->next == tail)
    {
        printf("Doubly linked list is empty.\n");
        return;
    }
    Node* current = header;
    while (current->next != tail)
        current = current->next;
    (current->prev)->next = tail;
    tail->prev = current->prev;
    free(current);
}


// Inserts new node at specified position
void insertAtPosition(Node* header, Node* tail, int data, int index)
{
    Node* newNode = createNode(data);
    Node* current = header;
    int counter = 0, isIndexValid = 0;
    while (current->next != tail)
    {
        if (counter == index - 1)
        {
            isIndexValid = 1;
            break;
        }
        current = current->next;
        counter++;
    }

    if (isIndexValid)
    {
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        (newNode->next)->prev = newNode;
    }
    else
    {
        printf("Invalid index.\n");
    }
}


// Deletes node at specified position
void deleteAtPosition(Node* header, Node* tail, int index)
{
    Node* current = header;
    int counter = 0, isIndexValid = 0;
    while (current->next != tail)
    {
        current = current->next;
        if (counter == index - 1)
        {
            isIndexValid = 1;
            break;
        }
        counter++;
    }

    if (isIndexValid)
    {
        Node* temp = current->prev;
        temp->next = current->next;
        (temp->next)->prev = temp;
        free(current);
    }
    else
    {
        printf("Invalid index.\n");
    }
}


// Inserts before/after node with given value
void insertAdjacentToNode(Node* header, Node* tail, int data, int value, int insertBefore)
{
    Node* newNode = createNode(data);
    Node* current = header;
    int isValueFound = 0;
    while (current->next != tail)
    {
        current = current->next;
        if (current->data == value)
        {
            isValueFound = 1;
            break;
        }
    }

    if (isValueFound)
    {
        if (insertBefore)
        {
            current = current->prev;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        (newNode->next)->prev = newNode;
    }
    else
    {
        printf("Node not found.\n");
    }
}


// Traverses in forward direction and displays the list
void traverseForward(Node* header, Node* tail)
{
    if (header->next == tail)
    {
        printf("Doubly linked list is empty.\n");
        return;
    }
    Node* current = header->next;
    printf("Doubly linked list elements: ");
    while (current != tail)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


// Traverses in reverse direction and displays the list
void traverseReverse(Node* header, Node* tail)
{
    if (tail->prev == header)
    {
        printf("Doubly linked list is empty.\n");
        return;
    }
    Node* current = tail->prev;
    printf("Doubly linked list elements: ");
    while (current != header)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}
