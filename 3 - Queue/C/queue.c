#include <stdio.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int count(Queue* q);
void enqueue(Queue* q, int element);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void clearQueue(Queue* q);

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 40);
    displayQueue(&q);

    clearQueue(&q);
    displayQueue(&q);

    return 0;
}

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

int isFull(Queue* q) {
    return q->rear == SIZE - 1;
}

int count(Queue* q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

void enqueue(Queue* q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    }
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        int element = q->items[q->front];
        if (q->front >= q->rear) { // Queue has only one element
            q->front = -1;
            q->rear = -1;
        }
        else {
            q->front++;
        }
        printf("Deleted -> %d\n", element);
        return element;
    }
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements are:\n");
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->items[i]);
        printf("\n");
    }
}

void clearQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    printf("Queue cleared!\n");
}