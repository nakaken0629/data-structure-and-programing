/* code: q3-5.c (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 128
#define ENQUEUE_SUCCESS  1
#define ENQUEUE_FAILURE -1
#define DEQUEUE_SUCCESS  2
#define DEQUEUE_FAILURE -2
#define PEEK_SUCCESS     3
#define PEEK_FAILURE    -3

void queue_init (int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

int enqueue (int q[], int *rear, int data) {
    if (*rear < MAX - 1) {
        *rear = *rear + 1;
        q[*rear] = data;
        return ENQUEUE_SUCCESS;
    } else {
        return ENQUEUE_FAILURE;
    }
}

int dequeue (int q[], int *front, int rear, int *data) {
    if (*front == rear) {
        return DEQUEUE_FAILURE;
    }
    *front = *front + 1;
    *data = q[*front];
    return DEQUEUE_SUCCESS;
}

int peek(int q[], int front, int rear, int *data) {
    if (front == rear) {
        return PEEK_FAILURE;
    }
    *data = q[front + 1];
    return PEEK_SUCCESS;
}

int main() {
    int queue[MAX];
    int front, rear, data;
    int stat;

    queue_init(&front, &rear);
    enqueue(queue, &rear, 680);
    enqueue(queue, &rear, 670);
    enqueue(queue, &rear, 690);
    enqueue(queue, &rear, 650);
    enqueue(queue, &rear, 660);
    dequeue(queue, &front, rear, &data);
    dequeue(queue, &front, rear, &data);
    dequeue(queue, &front, rear, &data);

    stat = peek(queue, front, rear, &data);
    if (stat == PEEK_SUCCESS) {
        printf("%d\n", data);
    } else {
        printf("QUEUE is empty\n");
    }
}
