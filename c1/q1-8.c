/* code: c1-8.c */
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand((unsigned) time(NULL));
    for (int i = 0; i < 100; i++) {
        int x = rand() % 10;
        int y = rand() % 10;
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
