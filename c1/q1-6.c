/* code: c1-2.c (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b);

int main() {
    int a[10] = {
        1, 5, 12, 24, 44, 48, 67, 73, 81, 98
    };

    int target;
    target = 67;
    int *result = bsearch (&target, a, 10, sizeof(int), compareInt);
    if (result == NULL) {
        printf ("Not found %d", target);
    } else {
        printf ("Found %d", target);
    }
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