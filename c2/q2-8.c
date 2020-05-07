/* code: c2-1.c (v1.18.0) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128
#define PUSH_SUCCESS 1
#define PUSH_FAILUER -1
#define POP_SUCCESS 2
#define POP_FAILUER -2

void stack_init (int *top) {
    *top = 0;
}

int push (int stack[], int *top, int data) {
    if (*top >= MAX) {
        /* stack overflow */
        return PUSH_FAILUER;
    } else {
        stack[*top] = data;
        (*top)++;
        return PUSH_SUCCESS;
    }
}

int pop (int stack[], int *top, int *data) {
    if ((*top) > 0) {
        *data = stack[ (*top) - 1];
        (*top)--;
        return POP_SUCCESS;
    } else {
        /* stack empty */
        return POP_FAILUER;
    }
}

int plus (int data1, int data2) {
    return data1 + data2;
}

int minus (int data1, int data2) {
    return data1 - data2;
}

int multiply (int data1, int data2) {
    return data1 * data2;
}

int divide (int data1, int data2) {
    return data1 / data2;
}

int main() {
    int stack[MAX];
    int top, data, data1, data2;
    char *tp;
    char oplist[] = "+-*/";
    int (*opfunclist[])(int, int) = {plus, minus, multiply, divide};

    char str[] = "5 1 2 + 4 * + 3 -";
    tp = strtok(str, " ");
    while(tp != NULL) {
        char *op = strstr(oplist, tp);
        if (op == NULL) {
            push(stack, &top, atoi(tp));
        } else {
            pop(stack, &top, &data2);
            pop(stack, &top, &data1);
            data = (*opfunclist[op - oplist])(data1, data2);
            push(stack, &top, data);
        }
        tp = strtok(NULL, " ");
    }
    pop(stack, &top, &data);
    printf("answer %d", data);
    return 0;
}