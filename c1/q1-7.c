/* code: q1-7.c */
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define ARRAY_SIZE 100000000

int compareInt(const void* a, const void* b);

int get_random() {
    int r;
    r =  ((rand() % 1000) * (rand() % 1000) * (rand() % 1000)) % (ARRAY_SIZE * 2);
    return r;
}

int main() {
    srand((unsigned) time(NULL));

    int *a;
    a = malloc(sizeof(int) * ARRAY_SIZE);
    if (a == NULL) {
        exit (-1);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        a[i] = get_random();
    }
    qsort(a, ARRAY_SIZE, sizeof(int), compareInt);

    time_t begin_time = time(NULL);
    int target;
    target = get_random();
    int *result = bsearch (&target, a, ARRAY_SIZE, sizeof(int), compareInt);
    if (result == NULL) {
        printf ("Not found %d\n", target);
    } else {
        printf ("Found %d\n", target);
    }
    printf("%.3f sec\n", difftime(time(NULL), begin_time));

    free(a);
    return 0;
}

int compareInt(const void* a, const void* b)
{
    int aNum = *(const int*)a;
    int bNum = *(const int*)b;

    if( aNum < bNum ){
        return -1;
    }
    else if( aNum > bNum ){
        return 1;
    }
    return 0;
}