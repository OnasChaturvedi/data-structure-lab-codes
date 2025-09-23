#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10
#define NAME_LEN 20

typedef struct {
    int docID;
    char docName[NAME_LEN];
} Job;

typedef struct {
    Job jobs[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, Job job) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add job %s (ID %d).\n", job.docName, job.docID);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->jobs[q->rear] = job;
    printf("Enqueued: %s (ID %d)\n", job.docName, job.docID);
}

Job dequeue(Queue *q) {
    Job job;
    if (isEmpty(q)) {
        printf("Queue is empty! No jobs to print.\n");
        job.docID = -1;
        strcpy(job.docName, "NULL");
        return job;
    }
    job = q->jobs[q->front];
    q->front++;
    return job;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nCurrent queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("[%d] %s\n", q->jobs[i].docID, q->jobs[i].docName);
    }
}

int main() {
    Queue printerQueue;
    int choice;
    srand(time(0));

    initQueue(&printerQueue);

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add a print job\n");
        printf("2. Process next job\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Job newJob;
            newJob.docID = rand() % 1000;
            sprintf(newJob.docName, "Doc%d", newJob.docID);
            enqueue(&printerQueue, newJob);
        }
        else if (choice == 2) {
            Job processedJob = dequeue(&printerQueue);
            if (processedJob.docID != -1)
                printf("Printing: %s (ID %d)\n", processedJob.docName, processedJob.docID);
        }
        else if (choice == 3) {
            displayQueue(&printerQueue);
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
