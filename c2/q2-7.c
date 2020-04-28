/* code: c2-1.c (v1.18.0) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128
#define PUSH_SUCCESS 1
#define PUSH_FAILUER -1
#define POP_SUCCESS 2
#define POP_FAILUER -2

int peek (int stack[], int *top, int *data) {
    if (*top > 0) {
        *data = stack[(*top) - 1];
        return POP_SUCCESS;
    } else {
        /* stack_empty */
        return POP_FAILUER;
    }
}

void stack_init (int *top) {
    *top = 0;
}

void display (int stack[], int top) {
    int i;
    printf ("STACX (%d) : ", top);
    for (i = 0; i < top; i++) {
        printf ("%d ", stack[i]);
    }
    printf ("\n");
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

int main() {
    int stack[MAX];
    int top, data;
    int len;
    char *str;

    str = malloc(sizeof(char) * 10000);
    sprintf(str, "This is a pen.");
    printf("%s\n", str);
    len = strlen(str);

    stack_init(&top);
    for (int i = 0; i < len; i++) {
        data = str[i];
        push(stack, &top, data);
    }
    for (int i = 0; i < len; i++) {
        pop(stack, &top, &data);
        printf("%c", data);
    }

    printf("\n");

    free(str);
    return 0;
}