#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    char name[50];
    int age;
    int priority;
} Patient;

typedef struct Node {
    Patient p;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, Patient pat) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->p = pat;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued patient: %s\n", pat.name);
}

Patient dequeue(Queue* q) {
    Patient pat;
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        strcpy(pat.name, "NULL");
        pat.age = -1;
        pat.priority = -1;
        return pat;
    }
    Node* temp = q->front;
    pat = temp->p;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    printf("Dequeued patient: %s\n", pat.name);
    return pat;
}

void displayQueue(Queue* q) {
    Node* temp = q->front;
    printf("Patients in queue:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Priority: %d\n", temp->p.name, temp->p.age, temp->p.priority);
        temp = temp->next;
    }
}

int main() {
    Queue q;
    int choice;
    Patient pat;

    initQueue(&q);
    while (1) {
        printf("\n1. Enqueue Patient\n2. Dequeue Patient\n3. Display Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient's name: ");
                scanf("%s", pat.name);
                printf("Enter age: ");
                scanf("%d", &pat.age);
                printf("Enter priority (higher number = higher priority): ");
                scanf("%d", &pat.priority);
                enqueue(&q, pat);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
