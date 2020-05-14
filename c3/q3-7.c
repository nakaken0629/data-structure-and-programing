/* code: q3-7.c (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 128
#define ENQUEUE_SUCCESS  1
#define ENQUEUE_FAILURE -1
#define DEQUEUE_SUCCESS  2
#define DEQUEUE_FAILURE -2

void queue_init (int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

int enqueue (int q[], int front, int *rear, int data) {
    if (*rear - front < MAX - 1) {
        *rear = *rear + 1;
        q[*rear % MAX] = data;
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
    *data = q[*front % MAX];
    return DEQUEUE_SUCCESS;
}

int main() {
    int queue[MAX];
    int front, rear, data;
    int stat;

    queue_init(&front, &rear);
    /* ダミーでリングを一周させる */
    for(int i = 0; i < MAX; i++) {
        enqueue(queue, front, &rear, 100);
        dequeue(queue, &front, rear, &data);
    }
    enqueue(queue, front, &rear, 100);
    enqueue(queue, front, &rear, 200);
    enqueue(queue, front, &rear, 300);
    enqueue(queue, front, &rear, 400);
    enqueue(queue, front, &rear, 500);

    while (rear - front) {
        stat = dequeue(queue, &front, rear, &data);
        if (stat == DEQUEUE_SUCCESS) {
            printf("%d (f:%d, r:%d)\n", data, front, rear);
        } else {
            printf("QUEUE is empty\n");
        }
    }
}
