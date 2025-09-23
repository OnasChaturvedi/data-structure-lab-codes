#include <stdio.h>
#define CAPACITY 5

int queue[CAPACITY];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % CAPACITY);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % CAPACITY;
    queue[rear] = value;
    printf("%d was enqueued to circular queue\n", value);
}

int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % CAPACITY;
    }
    printf("%d was dequeued from circular queue\n", value);
    return value;
}

void printQueue() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % CAPACITY;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}
